class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();

        queue<int> q;
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            s.push(sandwiches[n-i-1]);
            q.push(students[i]);
        }
        int cnt = 0;
        while (!q.empty() && cnt < q.size())
        {
            if (q.front() == s.top())
            {
                s.pop();
                q.pop();
                cnt = 0;
            }
            else
            {
                q.push(q.front());
                q.pop();
                cnt++;
            }
        }


        return q.size();
    }
};