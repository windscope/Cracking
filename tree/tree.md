# Summary of Binary tree data structure



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



## 2. Traversing the binary tree

- dfs traverse
  
  - pre order traverse// top down
    
    - recursive
      
      ``` c++
      void pre_order_traverse(TreeNode* node) {
      	if (node != nullptr) {
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
      			if (cur_node != nullptr) {
      				visit(cur_node);
      				node_stack.push(cur_node->right);
      				node_stack.push(cur_node->left);
      			}
      		}
      	}
      ```
      
    - moore traverse
      
      ``` c++
      void moore_in_order_traverse(TreeNode* root) {
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        while (cur != nullptr) {
            if (cur->left == nullptr) {
                visit(cur);
                cur = cur->right;
            } else {
                prev = cur->left;
                while(prev->right != nullptr && prev->right != cur) {
                    prev = prev->right;
                }
                if (prev->right == nullptr) {
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    prev->right = nullptr;
                    visit(cur);
                    cur = cur->right;
                }
            }
        }
      }
      ```
      
    - ​
      
    - parent-pointer traverse
    
  - in order traverse
    
    - recursive
      
      ``` c++
      void in_order_traverse(TreeNode* node) {
      	if (node != nullptr) {
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
      	TreeNode* cur_node = root;
          while (cur_node != nullptr || !node_stack.empty()) {
       		if (cur_node != nullptr) {
        			node_stack.push(cur_node);
                   cur_node = cur_node->left;
      		} else {
        			cur_node = node_stack.top();
                   node_stack.pop();
                   visit(cur_node);
                   cur_node = cur_node->right;
      		}
      	}
      }
      ```
      
    - moore traverse
      
      1. if current node’s left node is empty, visit the current node and then set current_node to its right node
      2. if current_node’s left child is not empty, find the front node of the current left sub tree (a front node is the last node visited by the left sub-tree)
         1. If the front node’s right child_node is empty, point its right child_node to the current_node
         2. if the front nodes right node is current node, then change it to nullptr, visit current node, set current node as its right child node
      3. repeat step 1 and step2 until current node is nullptr
      
      ``` c++
      void moore_in_order_traverse(TreeNode* root) {
      	TreeNode* cur = root;
        	TreeNode* prev = nullptr;
        	while (cur != nullptr) {
        		if (cur->left == nullptr) {
        			visit(cur);
                	cur = cur->right;
      		} else {
        			prev = cur->left;
                	while(prev->right != nullptr && prev->right != cur) {
        				prev = prev->right;
      				}
              	if (prev->right == nullptr) {
        				prev->right = cur;
      	            cur = cur->left;
      			} else {
        				prev->right = nullptr;
                    	visit(cur);
                    	cur = cur->right;
      			}
      		}
      	}
      }
      ```
      
      ​
      
    - parent-pointer traverse
    
  - post order traverse
    
    - recursive
      
      ``` c++
      void postorder_traverse(TreeNode* node) {
      	if (node != nullptr) {
        		postorder_traverse(node->left);
              postorder_traverse(node->right);
            	visit(node);
      	}
      }
      ```
      
      ​
      
    - iterative
      
      ``` c++
      // use two stack, first mimic the program stack, second to retain the order
      // 1. Push root to first stack.
      // 2. Loop while first stack is not empty
      //   2.1 Pop a node from first stack and push it to second stack
      //   2.2 Push left and right children of the popped node to first stack
      // 3. Print contents of second stack
      void postorder_traverse(TreeNode* root) {
      	stack<TreeNode*> root_stack, out_stack;
        	root_stack.push(root);
        	TreeNode* cur_node = nullptr;
        	while(!root_stack.empty()) {
            	cur_node = root_stack.top();
            	root_stack.pop();
            	if (cur_node != nullptr) {
        			root_stack.push(cur_node->left);
                	root_stack.push(cur_node->right);
                	out_stack.push(cur_node);
      		}
      	}
        	while (!out_stack.empty()) {
        		visit(out_stack.top());
            	out_stack.pop();
      	}
      }
      ```
      
      ``` c++
      // use one stack to iterative the tree
      
      void postorder_traverse(TreeNode* root) {
       	stack<TreeNode*> node_stack;
        	TreeNode* cur_node = root;
        	do {
        		while(cur_node != nullptr) {
      			if (cur_node->right != nullptr) {
        				node_stack.push(cur_node->right);
      			}
      	      	node_stack.push(cur_node);
                	cur_node = cur_node->left;
          	}
            	cur_node = node_stack.top();
            	node_stack.pop();
            	if (!node_stack.empty() && node_stack.top() == cur_node->right) {
        			node_stack.pop();
                	node_stack.push(cur_node);
                	cur_node = cur_node->right;
      		} else {
        			visit(cur_node);
              	cur_node = nullptr;
              }
      	} while (!node_stack.empty());
      }
      ```
      
      ​
      
    - parent-pointer traverse
      
      *
  
- bfs traverse
  
  ``` c++
  void bfs_node_traverse(TreeNode* node) {
      queue<TreeNode*> node_queue;
      node_queue.push(node);
      TreeNode* cur_node = nullptr;
      while (!node_queue.empty()) {
          cur_node = node_queue.front();
          node_queue.pop();
          if (cur_node != nullptr) {
              node_queue.push(cur_node->left);
              node_queue.push(cur_node->right);
              visit(cur_node);
          }
      }
  }
  ```
  
  ​
  
  ## 3 problem sets
  
  1. Symmetric tree:
     - Lesson learnt: can pass two nodes that are in the same layer to overcome that two disjoint nodes from different parents cannot be access via the same 
  2. ​