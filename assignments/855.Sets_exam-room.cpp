class ExamRoom {
public:
    vector<int> students;
    int n;
    ExamRoom(int n) {
        this->n = n;
    }
    
    int seat() {
        if(students.empty()){
            students.push_back(0);
            return 0;
        }
        int max_distance = students[0];
        int seat = 0;

        for(int i =0; i< students.size()-1; i++){
            int distance = (students [i+1]- students[i])/2; 
            if(distance>max_distance){
                max_distance=distance;
                seat = students[i]+distance;
            }
        }
        if(n-1-students.back()>max_distance){
            seat=n-1;
        }
        students.push_back(seat);
        sort(students.begin(),students.end());
        return seat;
    }
    
    void leave(int p) {
        students.erase(remove(students.begin(),students.end(),p),students.end());
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */