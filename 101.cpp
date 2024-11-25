// Учитывая корень двоичного дерева, проверьте, 
// является ли оно зеркалом самого себя (т. е. симметрично относительно своего центра).

bool is_symmetric(TreeNode* root) {
  function<bool(TreeNode*, TreeNode*)> dfs = [&](TreeNode* left, TreeNode* right) 
  {
      if (!left && !right) 
        return true; // оба узла пустые
    
      if (!left || !right || left->val != right->val) 
        return false; // один из узлов пуст или значения не равны
    
      return dfs(left->left, right->right) && dfs(left->right, right->left); // рекурсивный вызов
  };
  
  return dfs(root, root); // проверяем корень с самим собой
}
