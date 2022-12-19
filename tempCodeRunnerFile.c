Node* deleteNode(Node *root , int key ){
    if ( root == NULL ){
        printf("\nnot found\n");
        return NULL;
    }
    if ( root->data  > key ){
        root->left = deleteNode(root->left, key );
    }else if ( root->data < key ){
        root->right = deleteNode(root->right, key );
    }else{
        if ( root->left == NULL ){
            Node *temp = root->right;
            free(root);
            return temp;
        }
        if ( root->right == NULL ){
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *nt =  rightMost(root->left);
        root->data = nt->data ; 
        root->left = deleteNode(root->left , nt->data);
    }

    root->height = height(root);

    int balance = bal_factor(root);
    if ( balance > 1 && bal_factor(root->left)>= 0  ){
        return rightrotate(root); 
    }
    if ( balance < -1 && bal_factor(root->right) <= 0  ){
        return leftrotate(root); 
    }
    if ( balance > 1 && bal_factor(root->right) < 0 ){
        root->left =  leftrotate(root->left); 
        return rightrotate(root);
    }
    if ( balance <-1 && bal_factor(root->right) > 0 ){
        root->right = rightrotate(root->right) ; 
        return leftrotate(root); 
    }
    return root ; 
}
