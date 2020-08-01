#include <iostream>

// This is the class of the input root. Do not edit it.
class TreeNode {
public:
    int value;

    TreeNode *left = NULL;
    TreeNode *right = NULL;

    TreeNode(int value) {this->value = value;};

    void Add(TreeNode* node, bool dir) {
        if (dir == 0)
            left = node;
        else
            right = node;
    }
};

bool checkIfHasConnections(TreeNode* node) {
    return (node->left != NULL || node->right != NULL);
}

void iterStep(TreeNode* newOrigin, TreeNode* rightIn) {
    TreeNode* rootLeft = newOrigin->left;
    TreeNode* rootRight = newOrigin->right;

    if (rootLeft != NULL) {
        if (rootLeft->left != NULL)
            iterStep(rootLeft, newOrigin->right);
        rootLeft->right = rootRight;
    }

    if (rootRight != NULL) {
        if (checkIfHasConnections(rootRight)) {
            if (rightIn != NULL)
                iterStep(rootRight, rightIn->left);
            else
                iterStep(rootRight, NULL);
        }

        if (rightIn != NULL) {
            if (rightIn->left != NULL)
                rootRight->right = rightIn->left;
            else
                rootRight->right = NULL;
        } else {
            rootRight->right = NULL;
        }
    }
}


void convertToRightSiblingTree(TreeNode* root) {
    iterStep(root, NULL);
    if (root->right != NULL)
        root->right = NULL;
}

void check(TreeNode* newOrigin) {
    std::cout << newOrigin->value << std::endl;
    if (newOrigin->left != NULL) {
        TreeNode* rootLeft = newOrigin->left;
        std::cout << "rootLeft of " << newOrigin->value << ": " << rootLeft->value << std::endl;
        if (checkIfHasConnections(rootLeft)) {
            check(rootLeft);
        }
    }

    if (newOrigin->right != NULL) {
        TreeNode* rootRight = newOrigin->right;
        std::cout << "rootRight of " << newOrigin->value << ": " << rootRight->value << std::endl;
        if (checkIfHasConnections(rootRight)) {
            check(rootRight);
        }
    }
}

int main()
{
    // Create tree root
    TreeNode* root = new TreeNode(1);

    // Create leaf nodes
    TreeNode* two = new TreeNode(2);
    TreeNode* three = new TreeNode(3);
    TreeNode* four = new TreeNode(4);
    TreeNode* five = new TreeNode(5);
    TreeNode* six = new TreeNode(6);
    TreeNode* seven = new TreeNode(7);
    TreeNode* eight = new TreeNode(8);
    TreeNode* nine = new TreeNode(9);
    TreeNode* ten = new TreeNode(10);
    TreeNode* eleven = new TreeNode(11);
    TreeNode* twelve = new TreeNode(12);
    TreeNode* thirt = new TreeNode(13);
    TreeNode* fourt = new TreeNode(14);

    // Add leaf nodes to example tree
    root->Add(two,0);
    root->Add(three,1);
    two->Add(four,0);
    two->Add(five,1);
    three->Add(six,0);
    three->Add(seven,1);
    four->Add(eight,0);
    four->Add(nine,1);
    five->Add(ten,1);
    six->Add(eleven,0);
    eleven->Add(fourt,0);
    seven->Add(twelve,0);
    seven->Add(thirt,1);


    // ----------------------------------
    // TASK:
    // Convert tree to right sibling tree
    // ----------------------------------
    convertToRightSiblingTree(root);

    // ----------------------------------
    // CHECK
    // Check solution (walk tree and print out relationships)
    // ----------------------------------
    check(root);


    // Cleanup memory
    delete root;
    delete two;
    delete three;
    delete four;
    delete five;
    delete six;
    delete seven;
    delete eight;
    delete nine;
    delete ten;
    delete eleven;
    delete twelve;
    delete thirt;
    delete fourt;

}
