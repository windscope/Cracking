# Sumary of Binary tree data structure

## 1. Basic Concepts

- leaf
  
  - has no child(descendants)
  
- depth
  
  - the depth of a node n is the number of nodes on the search path from the root to n, not
    
    including n itself root has depth 0
  
- full binary tree
  
  - a binary tree in which every node other than the leaves has two children
  - the non-leaf nodes are the leaf nodes count -1
  
- perfect binary tree / complete binary tree
  
  - a full binary tree that all leaves are at the same depth
  - the node number can be compute as: 2^(h + 1) - 1
  
- A complete binary tree
  
  - every level, except(not required) the last is completely filled
  
- Traversing the binary tree
  
- dfs traverse
  
  - pre order traverse// top down
    
    - recursive  
      
      ``` c++
      		void pre_order_traverse(TreeNode* node) {
      			if (node) {
      				visit(node);
      				pre_order_traverse(node->left);
      				pre_order_traverse(node->right);
      			}
      		}
      ```
      
    - iterative
      
      ``` c++
      void pre_order_traverse(TreeNode* root) {
      
      		stack<TreeNode*> node_stack;
      
      		node_stack.push(root);
      
      		while(!node_stack.empty()) {
      
      			TreeNode* cur_node = node_stack.top();
      
      			node_stack.pop();
      
      			if (cur_node) {
      
      					visit(cur_node);
      
      					node_stack.push(cur_node->right);
      
      					node_stack.push(cur_node->left);
      
      			}
      
      		}
      
      	}
      ```
      
    - moore traverse
      
    - parent-pointer traverse
    
  - in order traverse
    
    - recursive
      
      ``` c++
      	void in_order_traverse(TreeNode* node) {
      		if (node) {
      			in_order_traverse(node->left);
      			visit(node);
      			in_order_traverse(node->right);
      		}
      	}
      ```
      
    - iterative
      
      ``` c++
      	void in_order_traverse(TreeNode* root) {
      		stack<TreeNode*> node_stack;
      		TreeNode* cur_node = node;
      			TreeNode* prev_node = nullptr;
      		while (cur_node != nullptr && !node_stack.empty()) {
      			if (cur_node == nullptr) {
      				prev_node = cur_node;
      				cur_node = node_stack.top();
      				node_stack.pop();
      			}
      			if (cur)
      			if (cur_node->right) {
      				node_stack.push(cur_node->right);
      			}
      			cur_node = cur_node->left;
      		}
      	}
      ```
      
    - moore traverse
      
    - parent-pointer traverse
    
  - post order traverse
    
    - recursive
      
    - iterative
      
    - parent-pointer traverse
      
      *
  
- bfs traverse