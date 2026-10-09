
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> directories;
        stringstream ss(path);
        string part;

        while (getline(ss, part, '/')) {
            if (part.empty() || part == ".") {
                continue;
            }

            if (part == "..") {
                if (!directories.empty()) {
                    directories.pop_back();
                }
            } else {
                directories.push_back(part);
            }
        }

        string result = "";

        for (string dir : directories) {
            result += "/" + dir;
        }

        return result.empty() ? "/" : result;
    }
};
