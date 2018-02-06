#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <memory>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

struct nameId 
{
    int id;
    std::string name;

};
using teacher = nameId;
using course = nameId;
using pupil = nameId;
using topic = nameId;

class School{
    unordered_map<int,teacher> teachers;
    unordered_map<int ,pupil> pupils;
    unordered_map<int, course> courses;
    unordered_map<int , vector<topic>> topics_by_course;
    unordered_map<int, set<int>> pupils_by_course;
public:
    template<typename ...T>
    void add_teacher(int id,const  T&...args)
    {
        teachers[id]=teacher{id,args...};
    }
    template<class...T>
    void add_course(int id,const T&...args)
    {
        courses[id] = course{id,args...};
    }
    template<typename ...T>
    void add_pupil(int id, const T&...args)
    {
        pupils[id]=pupil{id,args...};
    }
    template<class...T>
    void add_topic(int courseid,const string& topic_name, int teacher_id)
    {
        auto & topics= topics_by_course[courseid]; topics.push_back(topic{teacher_id,topic_name});
    }
    template<class T>
    void set_date(T&)
    {}

    template<class T, class U, class...V>
    void set_date(T&c,const U&u,const V&...args)
    {
        c.insert(u);
        set_date(c,args...);
    }
    template <class...T>
    void set_pupils_to_course(int courseid, const T&...ids)
    {
        auto & pupils = pupils_by_course[courseid];
         set_date(pupils, ids...);
    }
    template<class...T>
    void iterate_all_teachers_by_course(int cc,  )
    
    
};
int main()
{
    School s;
    s.add_teacher(1,"Romulo Rojas");
    s.add_teacher(2,"Alvaro Perez");
    s.add_teacher(3, "marcelo");
    s.add_course(1,"devin24");
    s.add_course(2,"devin25");
    s.add_pupil(1,"germal roes");
    s.add_pupil(2,"german, andre");
    s.add_pupil(3,"juan lopez");
    s.add_pupil(4, "marcelo pereira");
    s.add_topic(1,"c++",1);//estos dos serian topicos
    s.add_topic(1,"english",2);
    s.add_topic(2,"english",3);
    s.add_topic(2,"c#",1);

    s.set_pupils_to_course(1,1,2,3);
    s.set_pupils_to_course(2,1,4);

    s.iterate_all_teachers_by_course(1,[](auto& t){std::cout << t << '\n';});
    // std::cout << s.get_courseid_by_name("devin25") << '\n';
    // save_to_disk(const string & fn);
    // load_from_disk(const string& fn);

}