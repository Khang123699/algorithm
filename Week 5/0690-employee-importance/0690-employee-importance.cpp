/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> emp_map;
        for(Employee* emp:employees){
            emp_map[emp->id]=emp;
        }
       int total=0;
       queue<int> q;
       q.push(id);
       while(!q.empty()){
        int current_id=q.front();
        q.pop();
        Employee* emp= emp_map[current_id];
        total += emp->importance;
        for(int sub_id:emp->subordinates){
            q.push(sub_id);
        }
       }
    return total;
    }
};