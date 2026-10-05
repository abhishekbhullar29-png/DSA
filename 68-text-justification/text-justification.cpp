class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int lineLength = 0;

            // Find how many words can fit in this line
            while (j < n) {
                if (lineLength + words[j].length() + (j - i) > maxWidth)
                    break;

                lineLength += words[j].length();
                j++;
            }

            int wordCount = j - i;
            int spaces = maxWidth - lineLength;

            string line;

            // Last line OR line with only one word
            if (j == n || wordCount == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1)
                        line += " ";
                }

                // Add remaining spaces at the end
                line += string(maxWidth - line.length(), ' ');
            }
            else {
                // Fully justify the line
                int gaps = wordCount - 1;

                int spacesPerGap = spaces / gaps;
                int extraSpaces = spaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        // Left gaps get extra spaces first
                        int currentSpaces = spacesPerGap;

                        if (k - i < extraSpaces)
                            currentSpaces++;

                        line += string(currentSpaces, ' ');
                    }
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};