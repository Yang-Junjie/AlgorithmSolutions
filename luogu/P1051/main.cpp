#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Student {
    string name;
    double final_exam;
    double class_exam;
    char st;
    char west;
    int p;
    double bonus = 0;
};
int main()
{
    vector<Student> students;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        Student tmp;
        cin >> tmp.name >> tmp.final_exam >> tmp.class_exam >> tmp.st >> tmp.west >> tmp.p;
    students.push_back(tmp);
    }
    for (auto& student : students) {
        if (student.final_exam > 80 && student.p >= 1)
            student.bonus += 8000;
        if (student.final_exam > 85 && student.class_exam > 80)
            student.bonus += 4000;
        if (student.final_exam > 90)
            student.bonus += 2000;
        if(student.final_exam>85&&student.west=='Y')
            student.bonus+=1000;
        if(student.class_exam>80&&student.st=='Y')
            student.bonus+=850;
    }
    int sum = 0;
    Student the_no_one;
    for(auto student:students){
        if(student.bonus>the_no_one.bonus)
            the_no_one = student;
        sum+=student.bonus;
    }
    cout<<the_no_one.name<<'\n'<<the_no_one.bonus<<'\n'<<sum;
    return 0;
}
