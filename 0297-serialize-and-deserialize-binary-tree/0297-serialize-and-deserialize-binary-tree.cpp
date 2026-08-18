class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root)
            return "";

        string s;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (!curr) {
                s += "Null|";
                continue;
            }

            s += to_string(curr->val) + "|";

            q.push(curr->left);
            q.push(curr->right);
        }

        return s;
    }
    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;

        vector<string> v;
        string temp;

        for (char ch : data) {
            if (ch == '|') {
                v.push_back(temp);
                temp.clear();
            } else {
                temp += ch;
            }
        }

        if (v[0] == "Null")
            return nullptr;

        TreeNode* root = new TreeNode(stoi(v[0]));

        int i = 1;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty() && i < v.size()) {
            TreeNode* curr = q.front();
            q.pop();

            // left
            if (v[i] != "Null") {
                curr->left = new TreeNode(stoi(v[i]));
                q.push(curr->left);
            }
            i++;

            // right
            if (i < v.size() && v[i] != "Null") {
                curr->right = new TreeNode(stoi(v[i]));
                q.push(curr->right);
            }
            i++;
        }

        return root;
    }
};