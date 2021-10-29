#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <windows.h>

const int INC = 20;
const int INF = 0x3f;

using namespace std;

class Course
{
    //课程编号、课程名称、学分、总学时、理论学时、实验学时、开课学期、起止周、上课周数、课程性质、课容量、选课人数（初始为0）
private:
    string num;
    string title;
    string credit;
    string total_hour;
    string theoretical_hour;
    string experimental_hour;
    string start_semester;
    string start_end_week;
    string week;
    string nature;
    string class_content;
    string selector;
public:
    Course(string nm = "0", string tt = "0", string ct = "0", string tth = "0", string thh = "0", string exph = "0", string stsr = "0", string sew = "0", string clc = "0", string scr = "0")
    {
        num = nm;
        title = tt;
        credit = ct;
        total_hour = tth;
        theoretical_hour = thh;
        experimental_hour = exph;
        start_semester = stsr;
        start_end_week = sew;
        //week = wk;
        //nature = nt;
        class_content = clc;
        selector = scr;
    }
    void setNum(string nm)
    {
        num = nm;
    }
    void setTitle(string tt)
    {
        title = tt;
    }
    void setNature(string nt)
    {
        nature = nt;
    }
    void setCredit(string ct)
    {
        credit = ct;
    }
    void setTotalHour(string tth)
    {
        total_hour = tth;
    }
    void setTheoreticalHour(string thh)
    {
        theoretical_hour = thh;
    }
    void setExperimentalHour(string exph)
    {
        experimental_hour = exph;
    }
    void setStartSemester(string stsr)
    {
        start_semester = stsr;
    }
    void setStartEndWeek(string sew)
    {
        start_end_week = sew;
    }
    void setWeek(string wk)
    {
        week = wk;
    }
    void setClassContnet(string clc)
    {
        class_content = clc;
    }
    void setSelector(string scr)
    {
        selector = scr;
    }
    string getNum()
    {
        return num;
    }
    string getTitle()
    {
        return title;
    }
    string getNature()
    {
        return nature;
    }
    string getCredit()
    {
        return credit;
    }
    string getTotalHour()
    {
        return total_hour;
    }
    string getTheoreticalHour()
    {
        return theoretical_hour;
    }
    string getExperimentalHour()
    {
        return experimental_hour;
    }
    string getStartSemester()
    {
        return start_semester;
    }
    string getStartEndWeek()
    {
        return start_end_week;
    }
    string getWeek()
    {
        return week;
    }
    string getClassContnet()
    {
        return class_content;
    }
    string getSelector()
    {
        return selector;
    }
    void dispACourse()
    {
        //以“课程编号  课程名称  学分  总学时  理论学时  实验学时
        //开课学期  起止周  上课周数  /*课程性质  课容量*/  选课人数”的格式输出
        cout << num << "\t" << title << "\t" << credit << "\t" << total_hour << "\t" << theoretical_hour << "\t" << experimental_hour << "\t" << start_semester << "\t" << start_end_week << "\t" << class_content << "\t" << selector << "\n";

    }
    friend class InCourse;
    friend class StudentSelectCourse;
};

class Student
{
    //学号、姓名、学院、专业班级
private:
    string num;
    string name;
    string college;
    string classno;
public:
    Student(string num0 = "0", string name0 = "0", string college0 = "0", string clsn = "0")
    {
        //含有防BUG的默认参数填入
        num = num0;
        name = name0;
        college = college0;
        classno = clsn;
    }
    void setNum(string num0)//设置学号
    {
        num = num0;
    }
    void setName(string name0)//设置姓名
    {
        name = name0;
    }
    void setCollege(string college0)//设置学院
    {
        college = college0;
    }
    void setClassno(string clsn)//设置专业班级
    {
        classno = clsn;
    }
    string getNum()//返回学号
    {
        return num;
    }
    string getName()//返回姓名
    {
        return name;
    }
    string getCollege()//返回学院
    {
        return college;
    }
    string getClassno()//返回专业班级
    {
        return classno;
    }
    void dispAStudent()//以“学号  姓名  学院  专业班级”的格式输出
    {
        cout << num << "\t" << name << "\t" << college << "\t" << classno << "\n";
    }
    friend class InStudent;
    friend class StudentSelectCourse;
};


class SelectCourse
{
    //学号、姓名、课程编号、课程名称、开课学期、退选标志（0-已选，1-退选）
private:
    string num;
    string name;
    string course_num;
    string title;
    string start_semester;
    bool flag;
    SelectCourse(string num0 = "0", string name0 = "0", string coursenum0 = "0", string title0 = "0", string start_semester0 = "0", bool flag0 = 1)
    {
        //放BUG默认参数
        num = num0;
        name = name0;
        course_num = coursenum0;
        title = title0;
        start_semester = start_semester0;
        flag = flag0;
    }
    void setNum(string num0)//设置学号
    {
        num = num0;
    }
    void setName(string name0)//设置姓名
    {
        name = name0;
    }
    void setCourseNum(string num0)//设置课程编号
    {
        course_num = num0;
    }
    void setTitle(string title0)//设置课程名称
    {
        title = title0;
    }
    void setStartSemester(string startsemester0)//开课学期
    {
        start_semester = startsemester0;
    }
    void setFlag(bool flag0)
    {
        flag = flag0;
    }
    string getNum()
    {
        return num;
    }
    string getName()
    {
        return name;
    }
    string getCourseNum()
    {
        return course_num;
    }
    string getTitle()
    {
        return title;
    }
    string getStartSemester()
    {
        return start_semester;
    }
    bool getFlag()
    {
        return flag;
    }
    void dispSelectCourse()//以“学号   姓名  课程编号    课程名称    开课学期    退选标志”输出
    {
        cout << num << "\t" << name << "\t" << course_num << "\t" << title << "\t" << start_semester << "\t" << flag << endl;

    }
    friend class InSelectCourse;
    friend class StudentSelectCourse;

};

class InCourse
{
public:
    Course* course;
    int Coursecount;
    void write2Coursefile()
    {
        //编号、课程名称、课程性质、总学时、授课学时、实验或上机学时、学分、开课学期、上课周数、课容量、选课人数
        string num, title, nature;
        string total_hour, theoretical_hour, experimental_hour;
        string credit;
        string start_end_week, start_semester;
        string week, class_content, selector;
        int i;
        ofstream outf("d:\\courseee.txt", ios::out);
        //写入的文件名应该与读出的文件名相同；调试时可以取不同的文件名，以免覆盖掉原文件
        if (!outf)
        {
            cerr << "File could not be open." << endl;
        }
        outf << "课程信息\n";//将引号内容写入文件
        for (int i = 0; i < Coursecount; i++)
        {
            //获取所有书的信息并打印出来
            outf << course[i].getNum() << '\t' << course[i].getTitle() << '\t';
            outf << course[i].getCredit() << '\t' << course[i].getTotalHour() << '\t';
            outf << course[i].getTheoreticalHour() << '\t' << course[i].getExperimentalHour() << '\t' << course[i].getStartSemester();
            outf << '\t' << course[i].getStartEndWeek() << course[i].getClassContnet() << '\t' << course[i].getSelector() << '\n';
        }
        outf.close();//关闭文件
    }
    int inCourseFile(const char* fileName, int delLine)
    {
        //编号、课程名称、课程性质、总学时、授课学时、实验或上机学时、学分、起止周、开课学期、上课周数、课容量、选课人数
        string num, title, nature;
        string total_hour, theoretical_hour, experimental_hour;
        string credit;
        string start_end_week, start_semester;
        string week, class_content, selector;
        int i;
        ifstream inf(fileName, ios::in);//加载文件
        if (!inf)//判断是否成功打开
        {
            cerr << "课程数据加载失败！" << endl;
            int x0;
            x0 = MessageBox(GetForegroundWindow(), "课程数据加载失败！请检查数据文件是否存在。", "提示", 16);
            return 1;
        }
        char s[80];
        for (i = 1; i <= delLine; i++)
            inf.getline(s, 80);
        i = 0;
        //键入课程信息
        while (!inf.eof())
        {
            inf.getline(s, 80, '\t');
            inf.getline(s, 80, '\t');
            title = s;
            inf.getline(s, 80, '\t');
            inf.getline(s, 80, '\t');
            inf.getline(s, 80, '\t');
            inf.getline(s, 80, '\t');
            inf.getline(s, 80, '\t');
            inf.getline(s, 80, '\t');
            inf.getline(s, 80, '\t');
            if (title.length() > 0) i++;
        }
        Coursecount = i;
        cout << Coursecount << endl;
        inf.clear();
        inf.seekg(0, ios::beg);//指针移到开头
        for (i = 1; i <= delLine; i++)
            inf.getline(s, 80);
        course = new Course[Coursecount + INC];
        for (i = 0; i < Coursecount; i++)
        {
            inf.getline(s, 80, '\t');
            num = s;
            inf.getline(s, 80, '\t');
            title = s;
            inf.getline(s, 80, '\t');
            credit = s;
            inf.getline(s, 80, '\t');
            total_hour = s;
            inf.getline(s, 80, '\t');
            theoretical_hour = s;
            inf.getline(s, 80, '\t');
            experimental_hour = s;
            inf.getline(s, 80, '\t');
            start_end_week = s;
            inf.getline(s, 80, '\t');
            start_semester = s;
            inf.getline(s, 80, '\t');
            class_content = s;
            inf.getline(s, 80);
            selector = s;
            if (title.length() > 0)
            {
                if (num[0] == 10) num = num.substr(1);
                course[i] = Course();
                course[i].setNum(num);
                course[i].setTitle(title);
                course[i].setTotalHour(total_hour);
                course[i].setTheoreticalHour(theoretical_hour);
                course[i].setExperimentalHour(experimental_hour);
                course[i].setCredit(credit);
                course[i].setStartEndWeek(start_end_week);
                course[i].setStartSemester(start_semester);
                course[i].setClassContnet(class_content);
                course[i].setSelector(selector);
            }
        }
        inf.close();//关闭文件
        return Coursecount;
    }
    friend class StudentSelectCourse;
    int addCourse(string num = "0", string title = "0", string credit = "0", string total_hour = "0", string theoretical_hour = "0",
        string experimental_hour = "0", string start_semester = "0", string start_end_week = "0",
        string class_content = "0", string selector = "0")
    {
        //cout << "请键入信息：\n课程号\t课程名\t总学分\t总学时\t理论学时\t实验学时\t开课学期\t起止周\t课容量\t选课人数" << endl;
        //添加课程信息
        int i = Coursecount;
        course[i] = Course();
        course[i].setNum(num);
        course[i].setTitle(title);
        course[i].setTotalHour(total_hour);
        course[i].setTheoreticalHour(theoretical_hour);
        course[i].setExperimentalHour(experimental_hour);
        course[i].setCredit(credit);
        course[i].setStartEndWeek(start_end_week);
        course[i].setStartSemester(start_semester);
        course[i].setClassContnet(class_content);
        course[i].setSelector(selector);
        ++Coursecount;
        cout << "添加成功。" << endl;
        return Coursecount;
    }
    void searchCoursebytitle(string title)//按课程名
    {
        bool found = false;
        for (int i = 0; i < Coursecount; i++)
            if ((course[i].getTitle()).find(title) != string::npos)
            {
                //cout<<Course[i].getTitle()<< Course[i].getTitle().find(title)<<endl;
                cout << i << "\t";
                course[i].dispACourse();
                found = true;
                //return i;
            }
        if (!found)cout << "Course title:" << title << " not found." << endl;
        //return -1;
    }
    int searchCoursebytitlep(string title)//按课程名精确
    {
        for (int i = 0; i < Coursecount; i++)
            if (course[i].getTitle() == title)
            {
                //cout<<Course[i].getTitle()<< Course[i].getTitle().find(title)<<endl;
                cout << i << "\t";
                course[i].dispACourse();
                return i;
            }
        cout << "Course title:" << title << " not found." << endl;
        return -1;
    }
    int searchCoursebynum(string num)  //模糊查找包含num的串
    {
        bool found = false;
        for (int i = 0; i < Coursecount; i++)
            if ((course[i].getNum()).find(num) != string::npos)
            {
                //cout<<course[i].getTitle()<< course[i].getTitle().find(title)<<endl;
                cout << i << "\t";
                course[i].dispACourse();
                found = true;
                return i;
            }
        cout << "No num " << num << " existed." << endl;
        return -1;
    }
    int searchCoursebynump(string num)  //精确查找等于num的串
    {
        for (int i = 0; i < Coursecount; i++)
            if ((course[i].getNum()) == num)
            {
                //cout<<course[i].getTitle()<< course[i].getTitle().find(title)<<endl;
                cout << i << "\t";
                course[i].dispACourse();
                return i;
            }
        return -1;
    }
    void sortCoursebynum()//按num排序
    {
        for (int i = 0; i < Coursecount; i++)
        {
            int k = i;
            for (int j = i + 1; j < Coursecount; j++)
                if (course[j].getNum() < course[k].getNum()) k = j;
            //cout<<k<<" k&i "<<i<<" :"<<course[i].getNum()<<"---"<<course[k].getNum()<<endl;
            if (k != i)
            {
                Course t = course[i];
                course[i] = course[k];
                course[k] = t;
            }
        }
    }
    void sortCoursebytitle()//按title排序
    {
        for (int i = 0; i < Coursecount; i++)
        {
            int k = i;
            for (int j = i + 1; j < Coursecount; j++)
                if (course[j].getTitle() < course[k].getTitle()) k = j;
            if (k != i)
            {
                Course t = course[i];
                course[i] = course[k];
                course[k] = t;
            }
        }
    }
    void changeCoursebynum(string oldnum, string newnum)//通过num修改
    {
        int k = searchCoursebynump(oldnum);
        if (k >= 0)
        {
            course[k].setNum(newnum);
            cout << "changecoursebynum successed:" << endl;
            course[k].dispACourse();
        }
        else cout << "changeCourse failed. No Course of num=" << oldnum << endl;
    }
    void deleteCoursebynum(string num)//通过num删除
    {
        int k = searchCoursebynump(num);
        if (k >= 0)
        {
            cout << "Course to be deleted :" << endl;
            course[k].dispACourse();
            course[k] = course[Coursecount - 1];
            cout << "deleteCoursebynum successed:" << endl;
            Coursecount--;
            //return Coursecount;
        }
        else cout << "deleteCourse  failed. No Course of num=" << num << endl;
    }

    void changeCoursebytitle(string oldtitle, string newtitle)//通过title修改
    {
        int k = searchCoursebytitlep(oldtitle);
        if (k >= 0)
        {
            course[k].setTitle(newtitle);
            cout << "changeCoursebytitle successed:" << endl;
            course[k].dispACourse();
        }
        else cout << "changeCourse failed. No Course of title=" << oldtitle << endl;
    }

    void deleteCoursebytitle(string title)//通过title删除
    {
        int k = searchCoursebytitlep(title);
        if (k >= 0)
        {
            cout << "Course to be deleted :" << endl;
            course[k].dispACourse();
            course[k] = course[Coursecount - 1];
            cout << "deleteCoursebytitle successed:" << endl;
            Coursecount--;
            //return Coursecount;
        }
        else cout << "deleteCourse  failed. No Course of title=" << title << endl;

    }
};

class InStudent
{
public:
    //学生类和学生人数
    Student* student;
    int Studentcount;
    void write2Studentfile()//对学生信息的操作函数
    {

    }
    int inStudentFile(const char* fileName, int delLine)
    {
        //学号、姓名、学院、专业班级
        string num, name, college, classno;
        int i;
        //对文件的打开以及判断操作
        ifstream inf(fileName, ios::in);
        if (!inf)
        {
            cerr << "学生数据加载失败！" << endl;
            int x0;
            x0 = MessageBox(GetForegroundWindow(), "学生数据加载失败！请检查数据文件是否存在。", "提示", 16);
            return 1;
        }
        char s[80];
        for (i = 1; i <= delLine; i++)
            inf.getline(s, 80);
        i = 0;
        while (!inf.eof())//  { inf.getline( s, 80 ) ;    cout << s << endl ;  }
        {
            //键入信息
            inf.getline(s, 80, '\t');//num=s;
            inf.getline(s, 80, '\t');
            name = s;
            inf.getline(s, 80, '\t');//college=s;
            inf.getline(s, 80);//classno=s;
            if (name.length() > 0)        i++;
        }
        Studentcount = i;
        cout << Studentcount << endl;//输出学生数量
        inf.clear();
        inf.seekg(0, ios::beg);
        for (i = 1; i <= delLine; i++)
            inf.getline(s, 80);
        student = new Student[Studentcount + INC];
        for (i = 0; i < Studentcount; i++)
        {
            //键入信息
            inf.getline(s, 80, '\t');
            num = s;
            inf.getline(s, 80, '\t');
            name = s;
            inf.getline(s, 80, '\t');
            college = s;
            inf.getline(s, 80);
            classno = s;
            if (name.length() > 0)
            {
                if (num[0] == 10)num = num.substr(1);
                student[i] = Student();
                student[i].setNum(num);
                student[i].setName(name);
                student[i].setCollege(college);
                student[i].setClassno(classno);
            }
        }
        inf.close();
        return Studentcount;

    }
    int addStudent(string num, string name, string college, string classno)
    {
        //新增学生信息
        int i = Studentcount;
        student[i] = Student();
        student[i].setNum(num);
        student[i].setName(name);
        student[i].setCollege(college);
        student[i].setClassno(classno);
        ++Studentcount;
        return Studentcount;
    }
    void searchStudentbynum(string num)//通过学号查找学生，找到返回学生信息，否则提示未找到
    {
        bool found = false;
        for (int i = 0; i < Studentcount; i++)
            if ((student[i].getNum()).find(num) != string::npos)
            {
                cout << i << "\t";
                student[i].dispAStudent();
                found = true;
                //return i;
            }
        if (!found)cout << "Student of num: " << num << " not found" << endl;
        //return -1;
    }
    int searchStudentbynump(string num)//通过学号查找学生，找到返回学生信息和位置，否则返回-1
    {
        for (int i = 0; i < Studentcount; i++)
            if (student[i].getNum() == num)
            {
                cout << i << "\t";
                student[i].dispAStudent();
                return i;
            }
        return -1;
    }
    //自加函数。
    void searchStudentbyname(string name)//通过姓名查找学生，找到返回学生信息，否则提示未找到
    {
        bool found = false;
        for (int i = 0; i < Studentcount; i++)
            if ((student[i].getName()).find(name) != string::npos)
            {
                cout << i << "\t";
                student[i].dispAStudent();
                found = true;
                //return i;
            }
        if (!found)cout << "Student of name: " << name << " not found" << endl;
        //return -1;
    }
    int searchStudentbynamep(string name)//通过姓名查找学生，找到返回学生信息和位置，否则返回-1
    {
        for (int i = 0; i < Studentcount; i++)
            if (student[i].getName() == name)
            {
                cout << i << "\t";
                student[i].dispAStudent();
                return i;
            }
        return -1;
    }
    void searchStudentbyclassno(string classno)//通过班级查找学生，找到返回学生信息，否则提示未找到
    {
        bool found = false;
        for (int i = 0; i < Studentcount; i++)
            if ((student[i].getClassno()).find(classno) != string::npos)
            {
                cout << i << "\t";
                student[i].dispAStudent();
                found = true;
                //return i;
            }
        if (!found)cout << "Student of classno: " << classno << " not found" << endl;
        //return -1;
    }
    int searchStudentbyclassnop(string classno)//通过班级查找学生，找到返回学生信息和位置，否则返回-1
    {
        for (int i = 0; i < Studentcount; i++)
            if (student[i].getClassno() == classno)
            {
                cout << i << "\t";
                student[i].dispAStudent();
                return i;
            }
        return -1;
    }
    void sortStudentbynum()//按学号排序
    {
        for (int i = 0; i < Studentcount; i++)
        {
            int k = i;
            for (int j = i + 1; j < Studentcount; j++)
                if (student[j].getNum() < student[k].getNum()) k = j;
            //cout<<k<<" k&i "<<i<<" :"<<course[i].getNum()<<"---"<<course[k].getNum()<<endl;
            if (k != i)
            {
                Student t = student[i];
                student[i] = student[k];
                student[k] = t;
            }
        }
    }
    void sortStudentbycollege()//按学院排序
    {
        for (int i = 0; i < Studentcount; i++)
        {
            int k = i;
            for (int j = i + 1; j < Studentcount; j++)
                if (student[j].getCollege() < student[k].getCollege()) k = j;
            //cout<<k<<" k&i "<<i<<" :"<<course[i].getNum()<<"---"<<course[k].getNum()<<endl;
            if (k != i)
            {
                Student t = student[i];
                student[i] = student[k];
                student[k] = t;
            }
        }
    }
    void changeStudentbynum(string oldnum, string newnum)//通过学号修改学生
    {
        int k = searchStudentbynump(oldnum);
        if (k >= 0)
        {
            student[k].setNum(newnum);
            cout << "changestudentnum successed:" << endl;
            student[k].dispAStudent();
        }
        else cout << "changeStudentnum failed. No Student of num=" << oldnum << endl;
    }
    void changeStudentbyname(string oldname, string newname)//通过姓名修改学生
    {
        int k = searchStudentbynamep(oldname);
        if (k >= 0)
        {
            student[k].setName(newname);
            cout << "changestudentname successed:" << endl;
            student[k].dispAStudent();
        }
        else cout << "changeStudentname failed. No Student of name=" << oldname << endl;
    }
    void deleteStudentbynum(string num)//通过学号删除学生
    {
        int k = searchStudentbynump(num);
        if (k >= 0)
        {
            cout << "Student to be deleted :" << endl;
            student[k].dispAStudent();
            student[k] = student[Studentcount - 1];
            cout << "deleteStudentnum successed:" << endl;
            Studentcount--;
            //return Studentcount;
        }
        else cout << "deletenum  failed. No Student of num=" << num << endl;
    }
    void deleteStudentbyname(string name)//通过姓名删除学生
    {
        int k = searchStudentbynamep(name);
        if (k >= 0)
        {
            cout << "Student to be deleted :" << endl;
            student[k].dispAStudent();
            student[k] = student[Studentcount - 1];
            cout << "deleteStudentname successed:" << endl;
            Studentcount--;
            //return Studentcount;
        }
        else cout << "deletename  failed. No Student of name=" << name << endl;
    }
    friend class StudentSelectCourse;//声明友元类StudentSelectCourse
};

class InSelectCourse
{
public:
    //所选之课程和选课程数
    SelectCourse* selectcourse;
    int SelectCoursecount;
    void write2SelectCoursefile()
    {

    }
    int inSelectCourseFile(const char* fileName, int delLine)
    {
        //对选课程人以及所选之课程的操作
        //学号、姓名、课程号、课程名、开课学期、退选标志
        string num, name, Coursenum, title;
        string Selectdates;
        bool flag;
        int i;
        //文件打开的常规操作
        ifstream inf(fileName, ios::in);
        if (!inf)
        {
            cerr << "选课数据加载失败！" << endl;
            int x0;
            x0 = MessageBox(GetForegroundWindow(), "选课数据加载失败！请检查数据文件是否存在。", "提示", 16);
            return 1;
        }
        char s[80];
        for (i = 1; i <= delLine; i++)
            inf.getline(s, 80);
        i = 0;
        while (!inf.eof())
        {
            //从文件读入选课信息
            inf.getline(s, 80, '\t');
            num = s;
            inf.getline(s, 80, '\t');
            inf.getline(s, 80, '\t');
            inf.getline(s, 80, '\t');
            inf.getline(s, 80, '\t');
            inf.getline(s, 80);
            if (num.length() > 0) i++;
        }
        SelectCoursecount = i;
        cout << SelectCoursecount << endl;//显示课程数量
        inf.clear();
        inf.seekg(0, ios::beg);
        for (i = 1; i <= delLine; i++)
            inf.getline(s, 80);
        selectcourse = new SelectCourse[SelectCoursecount + INC];
        for (i = 0; i < SelectCoursecount; i++)
        {
            //从文件读入选的课程信息
            inf.getline(s, 80, '\t');
            num = s;
            inf.getline(s, 80, '\t');
            name = s;
            inf.getline(s, 80, '\t');
            Coursenum = s;
            inf.getline(s, 80, '\t');
            title = s;
            inf.getline(s, 80, '\t');
            Selectdates = s;
            inf >> flag;
            if (name.length() > 0)
            {
                if (num[0] == 10)num = num.substr(1);
                selectcourse[i] = SelectCourse();
                selectcourse[i].setFlag(flag);
                selectcourse[i].setNum(num);
                selectcourse[i].setName(name);
                selectcourse[i].setCourseNum(Coursenum);
                selectcourse[i].setTitle(title);
            }
        }
        inf.close();

        return SelectCoursecount;
    }
    friend class StudentSelectCourse;//声明友元类StudentSelectCourse
    int searchbystudentCourse(string studentnum, string Coursenum)//按学号和课程名查找信息，找到输出信息并返回位置，否则返回-1
    {
        for (int i = 0; i < SelectCoursecount; i++)
            if ((selectcourse[i].getNum()) == studentnum && (selectcourse[i].getCourseNum()) == Coursenum)
            {
                cout << i << "\t";
                selectcourse[i].dispSelectCourse();
                return i;
            }
        return -1;

    }
    int searchbystudentnum(string studentnum)//按学号查找信息
    {
        for (int i = 0; i < SelectCoursecount; i++)
            if ((selectcourse[i].getNum()) == studentnum)
            {
                cout << i << "\t";
                selectcourse[i].dispSelectCourse();
                return i;
            }
        cout << "No num " << studentnum << " existed." << endl;
        return -1;
    }
    void searchbyCoursetitle(string Coursetitle)//按课程名查找信息
    {
        for (int i = 0; i < SelectCoursecount; i++)
            if ((selectcourse[i].getTitle()) == Coursetitle)
            {
                cout << i << "\t";
                selectcourse[i].dispSelectCourse();
                //return i;
            }
            else
            {
                cout << "No Course named " << Coursetitle << endl;
            }
        //return -1;
    }
};

class StudentSelectCourse
{
    //课程信息、学生信息、选择课程信息
    InCourse crs;
    InStudent sdt;
    InSelectCourse sc;
public:
    void write2file()//对三个成员的操作
    {
        crs.write2Coursefile();
        sdt.write2Studentfile();
        sc.write2SelectCoursefile();

    }
    void init()//设置需要加载的文件
    {
        cout << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "现有课程数：";
        crs.inCourseFile("D:\\course.txt", 1);
        cout << "现有学生数：";
        sdt.inStudentFile("D:\\student.txt", 1);
        cout << "已选课程：";
        sc.inSelectCourseFile("D:\\studcourse.txt", 1);
        cout << "----------------------------------------------------" << endl;
        cout << endl;
    }
    void dispCourse()//显示课程信息
    {
        for (int i = 0; i < crs.Coursecount; i++)
        {
            cout << i << ":";
            crs.course[i].dispACourse();
        }
    }
    void dispStudent()//显示学生信息
    {
        for (int i = 0; i < sdt.Studentcount; i++)
        {
            cout << i << ":";
            sdt.student[i].dispAStudent();
        }
    }
    void dispSelectCourse()//显示选择课程信息
    {
        for (int i = 0; i < sc.SelectCoursecount; i++)
        {
            cout << i << ":";
            sc.selectcourse[i].dispSelectCourse();
        }
    }
    void dispCount()//显示课程、学生、选择课程数量
    {
        cout << endl;
        cout << "现有课程数：" << crs.Coursecount << endl;
        cout << "现有学生数：" << sdt.Studentcount << endl;
        cout << "已选课数：" << sc.SelectCoursecount << endl;
    }
    void addCourse()//新增课程函数
    {
        //课程号	课程名	总学分	总学时	理论学时	实验学时	开课学期	起止周	课容量	选课人数
        string num;
        string title;
        string credit;
        string total_hour;
        string theoretical_hour;
        string experimental_hour;
        string start_semester;
        string start_end_week;
        string class_content;
        string selector;
        char num0[80], tit0[80];
        string credit0 = "3";
        string total_hour0 = "54", theoretical_hour0 = "36", experimental_hour0 = "18", class_content0 = "39", selector0 = "0";
        cout << "请输入课程号、课程名、总学分、总学时、理论学时、实验学时、开课学期、起止周、课容量、选课人数：" << endl;
        string num1 = "BF003309", title0 = "算法分析与设计", stsr0 = "2016-2017-1", sew0 = "1-14";
        cin >> num1 >> title0 >> credit0 >> total_hour0 >> theoretical_hour0 >> experimental_hour0 >> stsr0 >> sew0 >> class_content0 >> selector0;
        crs.addCourse(num1, title0, credit0, total_hour0, theoretical_hour0, experimental_hour0, stsr0, sew0, class_content0, selector0);
        //新增课程
        int i = crs.Coursecount - 1;
        cout << i << ":";
        crs.course[i].dispACourse();//输出课程的信息
        cout << "现有课程数：" << i + 1 << endl;
        int x0;
        x0 = MessageBox(GetForegroundWindow(), "添加成功。", "提示", 64);
    }
    void addStudent()//新增学生
    {
        //学号、姓名、学院、专业班级
        string num, name, college, classno;
        char num0[80], nam[80], coll[80], clas[80];
        string num1 = "20151000", name0 = "王涛", college0 = "computer", class0 = "network class 1";
        cout << "请输入学号、姓名、学院、专业班级：" << endl;
        cin >> num1 >> name0 >> college0 >> class0;
        sdt.addStudent(num1, name0, college0, class0);
        //新增学生
        int i = sdt.Studentcount - 1;
        cout << i << ":";
        sdt.student[i].dispAStudent();//输出学生信息
        int x0;
        x0 = MessageBox(GetForegroundWindow(), "添加成功。", "提示", 64);
    }
    void searchCourse()//查找课程，调用之前的函数
    {
        cout << "----------------------------------------------------" << endl;
        cout << "2．课程信息查询：分别按课程编号,按课程名称等进行查询。" << endl;
        string num;
        string title = "算法分析与设计";
        int i, j, k, select;
        while (1)
        {
            cout << "课程信息查询：" << endl;
            cout << "1．按课程编号查询" << endl;
            cout << "2．按课程名称查询" << endl;
            cout << "0. return" << endl;
            cin >> select;
            cin.get();
            switch (select)
            {
            case 1:
                cout << "课程编号:";
                getline(cin, num, '\n');
                crs.searchCoursebynum(num);
                break;
            case 2:
                cout << "课程名称:";
                getline(cin, title, '\n');
                crs.searchCoursebytitle(title);
                break;
            case 0:
                return;
            }
        }
    }
    void sortCourse()//课程排序，调用之前的函数
    {
        cout << "----------------------------------------------------" << endl;
        int select;
        cout << "3．课程信息排序：按课程号、课程名等按升序进行排序。" << endl;
        cout << "课程信息排序：" << endl;
        cout << "1．按课程号排序" << endl;
        cout << "2．按课程名排序" << endl;
        cout << "0. return" << endl;
        cin >> select;
        switch (select)
        {
        case 1:
            cout << "课程号:";
            crs.sortCoursebynum();
            dispCourse();
            break;
        case 2:
            cout << "课程名:";
            crs.sortCoursebytitle();
            dispCourse();
            break;
        case 0:
            return;
        }
    }
    void editCourse()//改删课程，调用之前的函数
    {
        string oldtitle = "VisualBasic 程序设计教程", newtitle = "VisualBasic 程序设计教程-C", oldnum = "40667", newnum = "40667-C";
        int select;
        cout << "----------------------------------------------------" << endl;
        cout << "4．课程信息的修改、删除：按课程号或课程名进行课程的修改和删除。" << endl;
        while (1)
        {
            cout << "课程信息的修改、删除：" << endl;
            cout << "1．按课程号修改" << endl;
            cout << "2．按课程号删除" << endl;
            cout << "3．按课程名修改" << endl;
            cout << "4．按课程名删除" << endl;
            cout << "0. return" << endl;
            cin >> select;
            cin.get();
            switch (select)
            {
            case 1:
                cout << "旧课程号:";
                getline(cin, oldnum, '\n');
                cout << "新课程号:";
                getline(cin, newnum, '\n');
                cout << "changeCoursebynum: " << oldnum << " to " << newnum << endl;
                crs.changeCoursebynum(oldnum, newnum);
                //dispCourse();
                break;
            case 2:
                cout << "删除课程号:";
                getline(cin, oldnum, '\n');
                cout << "删除课程号:" << oldnum << endl;
                crs.deleteCoursebynum(oldnum);
                //dispCourse();
                break;
            case 3:
                cout << "旧课程名:";
                getline(cin, oldtitle, '\n');
                cout << "新课程名:";
                getline(cin, newtitle, '\n');
                cout << "changeCoursebytitle: " << oldtitle << " to " << newtitle << endl;
                crs.changeCoursebytitle(oldtitle, newtitle);
                //dispCourse();
                break;
            case 4:
                cout << "删除课程名:";
                getline(cin, oldtitle, '\n');
                cout << "deleteCoursebytitle: " << oldtitle << endl;
                crs.deleteCoursebytitle(oldtitle);
                //dispCourse();
                break;
            case 0:
                return;
            }
        }
    }
    void searchStudent()//查找学生，调用之前的函数
    {
        cout << "----------------------------------------------------" << endl;
        cout << "6.学生信息查询：分别按学号、姓名、专业班级等进行查询。" << endl;
        char tit[80];
        string num = "20076954", name = "汤武", classno = "地信07-1";
        int i, j, k, select;
        while (1)
        {
            cout << "学生信息查询：" << endl;
            cout << "1．按学号查询" << endl;
            cout << "2．按姓名查询" << endl;
            cout << "3．按专业班级查询" << endl;
            cout << "0. return" << endl;
            cin >> select;
            cin.get();
            switch (select)
            {
            case 1:
                cout << "学号:";
                getline(cin, num, '\n');
                sdt.searchStudentbynum(num);
                break;
            case 2:
                cout << "姓名:";
                getline(cin, name, '\n');
                sdt.searchStudentbyname(name);
                break;
            case 3:
                cout << "专业班级:";
                getline(cin, classno, '\n');
                sdt.searchStudentbyclassno(classno);
                break;
            case 0:
                return;
            }
        }
    }
    void sortStudent()//学生信息排序，调用之前的函数
    {
        int select;
        cout << "----------------------------------------------------" << endl;
        cout << "7．学生信息排序：按学号、学院等按升序进行排序。" << endl;
        while (1)
        {
            cout << "学生信息排序：" << endl;
            cout << "1．按学号排序" << endl;
            cout << "2．按学院排序" << endl;
            cout << "0. return" << endl;
            cin >> select;
            switch (select)
            {
            case 1:
                cout << "学号:";
                sdt.sortStudentbynum();
                dispStudent();
                break;
            case 2:
                cout << "学院:";
                sdt.sortStudentbycollege();
                dispStudent();
                break;
            case 0:
                return;
            }
        }
    }
    void editStudent()//改删学生，调用之前的函数
    {
        string oldnum = "20076954", newnum = "20076955", oldname = "汤武", newname = "谢本超", oldcollege = "资源与环境学院", newcollege = "资源与环境学院", oldclassno = "地信07-1", newclassno = "地信07-1";
        int select;
        cout << "----------------------------------------------------" << endl;
        cout << "8.学生信息的修改、删除：按学号+姓名进行学生信息的修改和删除。" << endl;
        while (1)
        {
            cout << "学生信息的修改、删除：" << endl;
            cout << "1．按学号修改" << endl;
            cout << "2．按学号删除" << endl;
            cout << "3．按姓名修改" << endl;
            cout << "4．按姓名删除" << endl;
            cout << "0. return" << endl;
            cin >> select;
            cin.get();
            switch (select)
            {
            case 1:
                cout << "旧学号:";
                getline(cin, oldnum, '\n');
                cout << "新学号:";
                getline(cin, newnum, '\n');
                cout << "changeStudentbynum: " << oldnum << " to " << newnum << endl;
                sdt.changeStudentbynum(oldnum, newnum);
                //dispStudent();
                break;
            case 2:
                cout << "删除学号:";
                getline(cin, oldnum, '\n');
                cout << "删除学号:" << oldnum << endl;
                sdt.deleteStudentbynum(oldnum);
                //dispStudent();
                break;
            case 3:
                cout << "旧姓名:";
                getline(cin, oldname, '\n');
                cout << "新姓名:";
                getline(cin, newname, '\n');
                cout << "changeStudentbyname: " << oldname << " to " << newname << endl;
                sdt.changeStudentbyname(oldname, newname);
                //dispStudent();
                break;
            case 4:
                cout << "删除姓名:";
                getline(cin, oldname, '\n');
                cout << "deleteStudentbyname: " << oldname << endl;
                sdt.deleteStudentbyname(oldname);
                //dispStudent();
                break;
            case 0:
                return;
            }
        }
    }
    void StudentSelectaCourse()//课程选择，调用之前的函数
    {
        cout << "----------------------------------------------------" << endl;
        cout << "9．输入学号+课程编号，如果该课程的课程信息表中的课容量大于选课人数，则可以选课，\n" << "选课后修改课程信息表中的选课人数 + 1，在学生选课表添加该同学的选课。" << endl;
        string sdtnum = "20061709", Coursenum = "33071", name, title;
        int select, sdtpos, Coursepos, y, m, d;
        while (1)
        {
            cout << "课程选择：" << endl;
            cout << "1．选择课程" << endl;
            cout << "0．return" << endl;
            cin >> select;
            cin.get();
            if (select == 0)return;
            cout << "Select学号:";
            getline(cin, sdtnum, '\n');
            cout << "Select课程号:";
            getline(cin, Coursenum, '\n');
            Coursepos = crs.searchCoursebynump(Coursenum);
            sdtpos = sdt.searchStudentbynump(sdtnum);
            if (Coursepos >= 0 && sdtpos >= 0)
            {
                string ss0 = crs.course[Coursepos].getClassContnet();
                const char* ss = ss0.c_str();
                int hm = atoi(ss);
                ostringstream os;
                os << (hm - 1);
                //int hm = 0;
                //string result = crs.course[Coursepos].getClassContnet();
                //stream << result;
                //stream >> hm;
                //int hm = stoi(crs.course[Coursepos].getClassContnet());
                if (hm > 0)
                {
                    name = sdt.student[sdtpos].getName();
                    title = crs.course[Coursepos].getTitle();
                    crs.course[Coursepos].setClassContnet(os.str()); //修改图课程信息表中的存馆数量
                    sc.selectcourse[sc.SelectCoursecount].setNum(sdtnum);
                    sc.selectcourse[sc.SelectCoursecount].setCourseNum(Coursenum);
                    sc.selectcourse[sc.SelectCoursecount].setName(name);
                    sc.selectcourse[sc.SelectCoursecount].setTitle(title);
                    sc.SelectCoursecount++;
                }
                else cout << Coursenum << " 课程容量=0" << ". can't be Selected. " << endl;
            }
            else
            {
                if (Coursepos < 0)cout << "No Course " << Coursenum << ". can't Select!" << endl;
                if (sdtpos < 0)cout << "No Student " << sdtnum << ". can't Select!" << endl;
            }
        }
    }
    void StudentreturnaCourse()//退课，调用之前的函数
    {
        cout << "----------------------------------------------------" << endl;
        cout << "10．学生退课：输入学号+课程编号，在学生选课表查找该学号学生对课程编号的选课，如果存在，则修改课程信息表中的选课人数-1，在学生选课表中设置该学号同学对课程的退选（退选标志设为1）。" << endl;
        char tit[80];
        string sdtnum = "20061709", Coursenum = "33071", name, title;
        int select, sdtpos, Coursepos, y, m, d;
        while (1)
        {
            cout << "学生退课：" << endl;
            cout << "1．退课" << endl;
            cout << "0．return" << endl;
            cin >> select;
            if (select == 0)return;
            cout << "return学号:";
            cin >> tit;
            //cout << tit << endl;
            //cin.getline(tit, 80);
            sdtnum = tit;
            cout << "return课程号:";
            cin >> tit;
            //cout << tit << endl;
            //cin.getline(tit, 80);
            Coursenum = tit;
            Coursepos = crs.searchCoursebynump(Coursenum);
            sdtpos = sdt.searchStudentbynump(sdtnum);
            if (Coursepos >= 0 && sdtpos >= 0)
            {
                string ss02 = crs.course[Coursepos].getClassContnet();
                const char* ss2 = ss02.c_str();
                int hm2 = atoi(ss2);
                ostringstream os2;
                os2 << (hm2 + 1);
                crs.course[Coursepos].setClassContnet(os2.str());
                SYSTEMTIME ct;
            }
            else
            {
                if (Coursepos < 0)cout << "No Course " << Coursenum << ". can't return!" << endl;
                if (sdtpos < 0)cout << "No Student " << sdtnum << ". can't return!" << endl;
            }
        }
    }
    void searchStudentSelectCourse()//课程查询，调用之前的函数
    {
        int select;
        string num, name, classno;
        cout << "----------------------------------------------------" << endl;
        cout << "11．选课查询：分别按学号、课程名、专业班级等进行查询。" << endl;
        while (1)
        {
            cout << "选课查询：" << endl;
            cout << "1.按学号查询" << endl;
            cout << "2.按课程号查询" << endl;
            cout << "3.按专业班级查询" << endl;
            cout << "0.return" << endl;
            cin >> select;
            cin.get();
            switch (select)
            {
            case 1:
                cout << "按学号查询:";
                getline(cin, num, '\n');
                sc.searchbystudentnum(num);
                break;
            case 2:
                cout << "按课程名查询:";
                getline(cin, name, '\n');
                crs.searchCoursebynum(name);
                break;
            case 3:
                cout << "按专业班级查询:";
                getline(cin, classno, '\n');
                sdt.searchStudentbyclassno(classno);
            case 0:
                return;
            }
        }

    }
};

int main()
{
    cout << "加载数据文件中......" << endl;
    StudentSelectCourse ssc;
    ssc.init();
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    cout << "现有课程：\n";
    cout << "课程号\t\t课程名\t\t总学分\t总学时\t理论学时实验学时起止周\t开课学期\t课容量\t选课人数" << endl;
    ssc.dispCourse();
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    cout << "现有学生：\n";
    cout << "学号\t\t姓名\t学院\t\t专业班级" << endl;
    ssc.dispStudent();
    cout << "----------------------------------------------------" << endl;
    cout << "已选课程：\n";
    cout << "学号\t\t姓名\t课程号\t\t课程名\t开课学期\t退选标志" << endl;
    ssc.dispSelectCourse();
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    ssc.dispCount();
    int x0;
    x0 = MessageBox(GetForegroundWindow(), "数据加载成功。", "提示", 64);
    cout << "数据加载成功" << endl;
    int select;
    while (1)
    {
        cout << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "菜单选择功能：" << endl;
        cout << "1. 课程信息添加功能：包括课程编号、课程名称、课程性质、总学时、授课学时、实验或上机学时、学分、开课学期、上课周数、课容量、选课人数等。" << endl;
        cout << "2．课程信息查询：分别按课程编号,按课程名称等进行查询。" << endl;
        cout << "3．课程信息排序：按课程编号,按课程名称等按升序进行排序。" << endl;
        cout << "4．课程信息的修改、删除：课程编号,按课程名称进行图书的修改和删除。" << endl;
        cout << "5．学生信息添加功能：包括学号、姓名、学院、专业班级等。" << endl;
        cout << "6．学生信息查询：分别按学号、姓名、专业班级等进行查询。" << endl;
        cout << "7．学生信息排序：按学号、学院等按升序进行排序。" << endl;
        cout << "8．学生信息的修改、删除：按学号+姓名进行学生信息的修改和删除。" << endl;
        cout << "9．学生选课：输入学号+课程编号，如果该课程的课程信息表中的课容量大于选课人数，则可以选课，" << endl;
        cout << "   选课后修改课程信息表中的选课人数+1，在学生选课表添加该同学的选课。" << endl;
        cout << "10.学生退课：输入学号+课程编号，在学生选课表查找该学号学生对课程编号的选课，" << endl;
        cout << "   如果存在，则修改课程信息表中的选课人数-1，在学生选课表中设置该学号同学对课程的退选（退选标志设为1）。" << endl;
        cout << "11.学生选课查询：分别按学号、课程编号、专业班级等进行查询。" << endl;
        cout << "0. exit" << endl;
        cout << "----------------------------------------------------" << endl;
        cin >> select;
        switch (select)
        {
        case 1:
            ssc.addCourse();
            ssc.dispCount();
            break;
        case 2:
            ssc.searchCourse();
            break;
        case 3:
            ssc.sortCourse();
            break;
        case 4:
            ssc.editCourse();
            break;
        case 5:
            ssc.addStudent();
            ssc.dispCount();
            break;
        case 6:
            ssc.searchStudent();
            break;
        case 7:
            ssc.sortStudent();
            break;
        case 8:
            ssc.editStudent();
            break;
        case 9:
            ssc.StudentSelectaCourse();
            break;
        case 10:
            ssc.StudentreturnaCourse();
            break;
        case 11:
            ssc.searchStudentSelectCourse();
            break;
        case 0:
            ssc.write2file();
            exit(0);
        }
    }
    return 0;
}
