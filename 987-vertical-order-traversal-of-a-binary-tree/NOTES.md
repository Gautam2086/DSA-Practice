0. declare queue as pair of(node*, int) => (ptr, horizontal dis)
1. Push value of current ele in map[horizontal dis]
2. Now, perform level order traversal
3. if(ele->left not null), then push in queue
4. if(ele->right not null), then push in queue