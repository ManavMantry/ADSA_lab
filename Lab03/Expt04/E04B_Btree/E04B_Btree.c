#include <stdio.h>
#include <stdlib.h>

#define MAX 3   // Max degree (for simplicity, B-Tree of order 3)

struct BTreeNode {
    int keys[MAX];
    struct BTreeNode* child[MAX + 1];
    int n;      // Current number of keys
    int leaf;   // 1 if leaf, 0 otherwise
};

// Create a new BTree node
struct BTreeNode* createNode(int leaf) {
    struct BTreeNode* node = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    node->leaf = leaf;
    node->n = 0;
    for (int i = 0; i <= MAX; i++)
        node->child[i] = NULL;
    return node;
}

// Traversal (inorder-like)
void traverse(struct BTreeNode* root) {
    if (root != NULL) {
        int i;
        for (i = 0; i < root->n; i++) {
            traverse(root->child[i]);
            printf("%d ", root->keys[i]);
        }
        traverse(root->child[i]);
    }
}

// Search
struct BTreeNode* search(struct BTreeNode* root, int k) {
    int i = 0;
    while (i < root->n && k > root->keys[i])
        i++;
    if (i < root->n && root->keys[i] == k)
        return root;
    if (root->leaf)
        return NULL;
    return search(root->child[i], k);
}

// Split child
void splitChild(struct BTreeNode* parent, int i, struct BTreeNode* y) {
    int t = (MAX + 1) / 2;
    struct BTreeNode* z = createNode(y->leaf);
    z->n = t - 1;

    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];
    if (!y->leaf) {
        for (int j = 0; j < t; j++)
            z->child[j] = y->child[j + t];
    }
    y->n = t - 1;

    for (int j = parent->n; j >= i + 1; j--)
        parent->child[j + 1] = parent->child[j];
    parent->child[i + 1] = z;

    for (int j = parent->n - 1; j >= i; j--)
        parent->keys[j + 1] = parent->keys[j];
    parent->keys[i] = y->keys[t - 1];
    parent->n++;
}

// Insert non-full
void insertNonFull(struct BTreeNode* node, int k) {
    int i = node->n - 1;
    if (node->leaf) {
        while (i >= 0 && k < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = k;
        node->n++;
    } else {
        while (i >= 0 && k < node->keys[i])
            i--;
        i++;
        if (node->child[i]->n == MAX) {
            splitChild(node, i, node->child[i]);
            if (k > node->keys[i])
                i++;
        }
        insertNonFull(node->child[i], k);
    }
}

// Insert
struct BTreeNode* insert(struct BTreeNode* root, int k) {
    if (root == NULL) {
        root = createNode(1);
        root->keys[0] = k;
        root->n = 1;
        return root;
    }
    if (root->n == MAX) {
        struct BTreeNode* s = createNode(0);
        s->child[0] = root;
        splitChild(s, 0, root);
        int i = 0;
        if (s->keys[0] < k)
            i++;
        insertNonFull(s->child[i], k);
        return s;
    } else {
        insertNonFull(root, k);
        return root;
    }
}

// Find predecessor
int getPred(struct BTreeNode* node, int idx) {
    struct BTreeNode* cur = node->child[idx];
    while (!cur->leaf)
        cur = cur->child[cur->n];
    return cur->keys[cur->n - 1];
}

// Find successor
int getSucc(struct BTreeNode* node, int idx) {
    struct BTreeNode* cur = node->child[idx + 1];
    while (!cur->leaf)
        cur = cur->child[0];
    return cur->keys[0];
}

// Merge children
void merge(struct BTreeNode* node, int idx) {
    struct BTreeNode* child = node->child[idx];
    struct BTreeNode* sibling = node->child[idx + 1];
    child->keys[(MAX - 1) / 2] = node->keys[idx];

    for (int i = 0; i < sibling->n; ++i)
        child->keys[i + (MAX + 1) / 2] = sibling->keys[i];
    if (!child->leaf) {
        for (int i = 0; i <= sibling->n; ++i)
            child->child[i + (MAX + 1) / 2] = sibling->child[i];
    }

    for (int i = idx + 1; i < node->n; ++i)
        node->keys[i - 1] = node->keys[i];
    for (int i = idx + 2; i <= node->n; ++i)
        node->child[i - 1] = node->child[i];

    child->n += sibling->n + 1;
    node->n--;
    free(sibling);
}

// Borrow from previous
void borrowFromPrev(struct BTreeNode* node, int idx) {
    struct BTreeNode* child = node->child[idx];
    struct BTreeNode* sibling = node->child[idx - 1];

    for (int i = child->n - 1; i >= 0; --i)
        child->keys[i + 1] = child->keys[i];
    if (!child->leaf) {
        for (int i = child->n; i >= 0; --i)
            child->child[i + 1] = child->child[i];
    }
    child->keys[0] = node->keys[idx - 1];
    if (!child->leaf)
        child->child[0] = sibling->child[sibling->n];
    node->keys[idx - 1] = sibling->keys[sibling->n - 1];
    child->n++;
    sibling->n--;
}

// Borrow from next
void borrowFromNext(struct BTreeNode* node, int idx) {
    struct BTreeNode* child = node->child[idx];
    struct BTreeNode* sibling = node->child[idx + 1];
    child->keys[child->n] = node->keys[idx];
    if (!child->leaf)
        child->child[child->n + 1] = sibling->child[0];
    node->keys[idx] = sibling->keys[0];
    for (int i = 1; i < sibling->n; ++i)
        sibling->keys[i - 1] = sibling->keys[i];
    if (!sibling->leaf) {
        for (int i = 1; i <= sibling->n; ++i)
            sibling->child[i - 1] = sibling->child[i];
    }
    child->n++;
    sibling->n--;
}

// Delete key
void deleteKey(struct BTreeNode* node, int k) {
    int idx = 0;
    while (idx < node->n && node->keys[idx] < k)
        ++idx;

    if (idx < node->n && node->keys[idx] == k) {
        if (node->leaf) {
            for (int i = idx + 1; i < node->n; ++i)
                node->keys[i - 1] = node->keys[i];
            node->n--;
        } else {
            if (node->child[idx]->n >= (MAX + 1) / 2) {
                int pred = getPred(node, idx);
                node->keys[idx] = pred;
                deleteKey(node->child[idx], pred);
            } else if (node->child[idx + 1]->n >= (MAX + 1) / 2) {
                int succ = getSucc(node, idx);
                node->keys[idx] = succ;
                deleteKey(node->child[idx + 1], succ);
            } else {
                merge(node, idx);
                deleteKey(node->child[idx], k);
            }
        }
    } else {
        if (node->leaf) {
            printf("Key %d not found\n", k);
            return;
        }
        int flag = (idx == node->n);
        if (node->child[idx]->n < (MAX + 1) / 2) {
            if (idx != 0 && node->child[idx - 1]->n >= (MAX + 1) / 2)
                borrowFromPrev(node, idx);
            else if (idx != node->n && node->child[idx + 1]->n >= (MAX + 1) / 2)
                borrowFromNext(node, idx);
            else {
                if (idx != node->n)
                    merge(node, idx);
                else
                    merge(node, idx - 1);
            }
        }
        if (flag && idx > node->n)
            deleteKey(node->child[idx - 1], k);
        else
            deleteKey(node->child[idx], k);
    }
}

// Main
int main() {
    struct BTreeNode* root = NULL;
    int n, val;

    printf("Enter number of elements to insert: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("B-Tree traversal after insertions: ");
    traverse(root);
    printf("\n");

    printf("Enter number of elements to delete: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        if (root != NULL)
            deleteKey(root, val);
    }

    printf("B-Tree traversal after deletions: ");
    traverse(root);
    printf("\n");

    return 0;
}
