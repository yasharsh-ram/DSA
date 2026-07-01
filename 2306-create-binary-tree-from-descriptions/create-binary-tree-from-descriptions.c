/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* createBinaryTree(int** descriptions, int descriptionsSize,
                                  int* descriptionsColSize) {
    bool ischild[100001] = {false};
    struct TreeNode* nodes[100001] = {NULL};
    for (int i = 0; i < descriptionsSize; i++) {
        int parent = descriptions[i][0];
        int child = descriptions[i][1];
        int isleft = descriptions[i][2];
        // printf("%d %d %d",parent,child,isleft);
        if (nodes[parent] == NULL) {
            nodes[parent] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            nodes[parent]->val = parent;
            nodes[parent]->left = NULL;
            nodes[parent]->right = NULL;
        }
        if (nodes[child] == NULL) {
            nodes[child] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            nodes[child]->val = child;
            nodes[child]->left = NULL;
            nodes[child]->right = NULL;
        }
        if (isleft) {
            nodes[parent]->left = nodes[child];
        } else {
            nodes[parent]->right = nodes[child];
        }
        ischild[child] = true;
    }
    for (int i = 1; i < 100001; i++) {
        if (nodes[i] != NULL && !ischild[i]) {
            return nodes[i];
        }
    }
    return NULL;
}