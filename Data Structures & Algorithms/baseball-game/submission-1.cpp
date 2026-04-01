class Solution {
public:
    int calPoints(vector<string>& operations) {
        int res=0;
        stack<int> record;

        for(const string& op:operations){
            if(op=="+"){
                int top=record.top();
                record.pop();
                int newTop=top+record.top();
                record.push(top);
                record.push(newTop);
                res+=record.top();
            }
            else if(op=="D"){
                int newTop=2*record.top();
                record.push(newTop);
                res+=record.top();
            }
            else if(op=="C"){
                res-=record.top();
                record.pop();
            }
            else {
                record.push(stoi(op));
                res+=record.top();
            }

        }
        return res;
    }
};