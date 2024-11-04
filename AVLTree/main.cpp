void AVL::insert(const int &v) {
    Node *newNode = new Node(v);

    if (root == nullptr) {
        root = newNode;
    } else {
        Node *current = root;
        Node *parent = nullptr;

        while (current) {
            parent = current;
            if (v < current->val) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (v < parent->val) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }

    // Update height from the current node to the root
    Node *current = newNode;
    while (current) {
        int leftHeight = getHeight(current->left);
        int rightHeight = getHeight(current->right);
        current->height = 1 + max(leftHeight, rightHeight);
        int balance = leftHeight - rightHeight;

        // Perform rotations if needed to balance the tree
        if (balance > 1) {
            if (v < current->left->val) {
                rotateRight(current);
            } else {
                rotateLeftRight(current);
            }
        } else if (balance < -1) {
            if (v > current->right->val) {
                rotateLeft(current);
            } else {
                rotateRightLeft(current);
            }
        }

        current = current->parent;
    }
}
