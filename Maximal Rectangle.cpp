
        class Solution {
        public:
        // same as to find the area of histogram.
            int largestRectangleArea(vector < int > & histo) {
            stack < int > st;
            int maxA = 0;
            int n = histo.size();
            for (int i = 0; i <= n; i++) {
                while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
                int height = histo[st.top()];
                st.pop();
                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                maxA = max(maxA, width * height);
                }
                st.push(i);
            }
            return maxA;
            }
            // here we are traversing row wise and at each pass traversing 
            // the next row by adding the prev row with with it 
            // after the row addition it is similar to area of histogram problem
            // just need to find the left min and right min and like that..
            int maximalRectangle(vector<vector<char>>& matrix) {
                int maxiArea = 0, n = matrix.size(), m = matrix[0].size();
                vector<int> height(m,0);
                
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        if(matrix[i][j] == '1') height[j]++;
                        else height[j] = 0;
                    }   
                    int area = largestRectangleArea(height);
                    maxiArea = max(maxiArea,area);
                }
                return maxiArea;
            }
        };      