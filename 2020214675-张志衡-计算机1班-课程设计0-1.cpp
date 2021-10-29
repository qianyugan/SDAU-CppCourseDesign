#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <windows.h>

const int INC = 20;
const int INF = 0x3f;

using namespace std;

class Date
{
public:
    int day, month, year;//日期，月份，年份
    Date(int d = 1, int m = 1, int y = 2012)//判断日期的合法性
    {
        if (d > 0 && d < 32)day = d;
        else day = 1;//限制日在1—31之间，否则设为1
        if (m > 0 && m < 13)month = m;
        else m = 1;//限制月在1—12之间，否则设为1
        if (y > 0)year = y;//限制年大于0，否则设为2012
        else year = 2012;
    }
    void setDay(int d)//设定日
    {
        day = d;
    }
    void setMonth(int m)//设定月
    {
        month = m;
    }
    void setYear(int y)//设定年
    {
        year = y;
    }
    int getDay()//返回当前日
    {
        return day;
    }
    int getMonth()//返回当前月
    {
        return month;
    }
    int getYear()//返回当前年
    {
        return year;
    }
    void disp()//以“年/月/日”的格式输出
    {
        cout << year << "/" << month << "/" << day;
    }
    Date operator+(int dtmp);//重载+运算符使之可以操作Date类
    bool isLeapYear(int yy);//判断是否是闰年
};

bool Date::isLeapYear(int yy)//判断是否是闰年
{
    if (yy % 400 == 0)
        return true;
    else if (yy % 100 != 0 && yy % 4 == 0)
        return true;
    else return false;
}

Date Date::operator+(int dtmp)//重载+运算符使之可以操作Date类
{
    //bool Date::isLeapYear(int yy);
    int yy = year, mm = month, dd = day, mtmp, m2;
    bool flag;
    //将天数转换成年月日的格式加到Date类的对象中的对应成员里
    while (dtmp >= 0)
    {
        if (isLeapYear(yy))
        {
            dtmp -= 366;
            flag = true;
        }
        else
        {
            dtmp -= 365;
            flag = false;
        }
        yy++;
    }
    if (flag)
        dtmp += 366;
    else dtmp += 365;
    yy--;
    if (isLeapYear(yy))
    {
        m2 = 29;
    }
    else
    {
        m2 = 28;
    }
    mtmp = dtmp + dd;
    int m_day[] = { 0,31,m2,31,30,31,30,31,31,30,31,30,31 };
    for (; mtmp > m_day[mm];)
    {
        mtmp -= m_day[mm];
        if (mm == 12)
        {
            mm = 0;
            yy++;
        }
        mm++;
    }
    dd = mtmp;
    Date dt(yy, mm, dd);
    return dt;
}
class Book
{
    //书号、书名、作者、出版社、出版日期、出版定价、存馆数量
private:
    string num;
    string title;
    string author;
    string publisher;
    Date publishdate;
    float price;
    int howmany;
public:
    Book(string num0 = "24416-5", string title0 = "数据结构", string author0 = "王红梅,胡明,王涛",
        string pub0 = "清华大学出版社", int bd = 1, int bm = 1, int by = 2012, float pr = 29.0, int ct = 10) :publishdate((bd, bm, by))
    {
        //默认以以上格式输入，防止非法填入和空填导致的程序错误
        num = num0;
        title = title0;
        author = author0;
        publisher = pub0;
        price = pr;
        howmany = ct;
    }
    void setNum(string num0)//设置图书编号
    {
        num = num0;
    }
    void setTitle(string title0)//设置书名
    {
        title = title0;
    }
    void setAuthor(string author0)//设置作者
    {
        author = author0;
    }
    void setPublisher(string publisher0)//设置出版社
    {
        publisher = publisher0;
    }
    void setPublishdate(int bd, int bm, int by)//设置出版日期
    {
        Date d(bd, bm, by);//Date格式的日期
        publishdate = d;
    }
    void setHowmany(int ct)//设置馆存数量
    {
        howmany = ct;
    }
    void setPrice(float pr)//设置图书价格
    {
        price = pr;
    }
    string getNum()//返回编号
    {
        return num;
    }
    string getTitle()//返回书名
    {
        return title;
    }
    string getAuthor()//返回作者
    {
        return author;
    }
    string getPublisher()//返回出版社
    {
        return publisher;
    }
    Date getPublishdate()//返回出版日期
    {
        return publishdate;
    }
    int getHowmany()//返回馆存数量
    {
        return howmany;
    }
    float getPrice()//返回价格
    {
        return price;
    }
    void dispABook()//以“编号  书名  作者  出版社 出版日期 价格  馆存数量”的格式输出
    {
        cout << num << '\t' << title << '\t' << author << '\t' << publisher << '\t';
        getPublishdate().disp();
        cout << '\t' << price << '\t' << howmany << '\n';
    }
    friend class InBook;//声明InBook为Book的友元类
    friend class ReaderBorrowBook;//声明ReaderBookBorrow为Book的友元类
};
class Reader
{
    //学号、姓名、学院、专业班级
private:
    string num;
    string name;
    string college;
    string classno;
public:
    Reader(string num0 = "20150000", string name0 = "NoName", string college0 = "信息学院", string clsn = "网络工程15-1")
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
    void dispAReader()//以“学号  姓名  学院  专业班级”的格式输出
    {
        cout << num << "\t" << name << "\t" << college << "\t" << classno << "\n";
    }
    friend class Inreader;//声明Reader的友元类Inreader
    friend class ReaderBorrowBook;//声明Reader的友元类ReaderBorrowBook
};

class BorrowBook
{
    //学号、姓名、书号、书名、借阅日期、应还日期、归还日期
private:
    string num;
    string name;
    string booknum;
    string title;
    string college;
    Date borrowdate;
    Date toreturndate;
    Date returndate;
    BorrowBook(string num0 = "20150000", string name0 = "NoName", string booknum0 = "24416-5",
        string title0 = "数据结构", int bd = 1, int bm = 1, int by = 2012, int td = 1, int tm = 5, int ty = 2012, int rd = 1, int rm = 3, int ry = 2012, string college0 = "信息学院")
        :borrowdate(bd, bm, by), toreturndate(td, tm, ty), returndate(rd, rm, ry)
    {
        //防BUG默认参数
        num = num0;
        name = name0;
        booknum = booknum0;
        title = title0;
        college = college0;
    }
    void setNum(string num0)//设置学号
    {
        num = num0;
    }
    void setName(string name0)//设置姓名
    {
        name = name0;
    }
    void setBookNum(string num0)//设置书号
    {
        booknum = num0;
    }
    void setTitle(string title0)//设置书名
    {
        title = title0;
    }
    void setCollege(string college0)
    {
        college = college0;
    }
    void setBorrowdate(int bd, int bm, int by)//设置借阅日期
    {
        Date d(bd, bm, by);
        borrowdate = d;
    }
    void setToreturndate(int td, int tm, int ty)//设置应还日期
    {
        Date d(td, tm, ty);
        toreturndate = d;
    }
    void setReturndate(int rd, int rm, int ry)//设置归还日期
    {
        Date d(rd, rm, ry);
        returndate = d;
    }
    string getCollege()
    {
        return college;
    }
    string getNum()//返回学号
    {
        return num;
    }
    string getName()//返回姓名
    {
        return name;
    }
    string getBookNum()//返回书号
    {
        return booknum;
    }
    string getTitle()//返回书名
    {
        return title;
    }
    Date getBorrowdate()//返回借阅日期
    {
        return borrowdate;
    }
    Date getReturndate()//返回应还日期
    {
        return returndate;
    }
    Date getToreturndate()//返回归还日期
    {
        return toreturndate;
    }
    void dispBorrowBook()//以“学号 姓名  书号  书名  借阅日期    应还日期    归还日期”输出
    {
        cout << num << "\t" << name << "\t" << booknum << "\t" << title << "\t" << college << "\t";
        borrowdate.disp();
        cout << "\t";
        toreturndate.disp();
        cout << "\t";
        returndate.disp();
        cout << "\n";
    }
    friend class InBorrowBook;//设置BorrowBook的友元类InBorrowBook
    friend class ReaderBorrowBook;//设置BorrowBook的友元类ReaderBorrowBook

};
void string2date(string pdates, int d[])//日期格式化函数，将格式化好的日月年填入d[0]、d[1]和d[2]
{
    int k = 0, by, bm, bd;
    while ((pdates[k] < '0' || pdates[k]>'9') && k < pdates.length())k++;
    by = 0;
    for (; pdates[k] != '/' && k < pdates.length(); k++)
        by = by * 10 + pdates[k] - '0';
    k++;
    bm = 0;
    for (; pdates[k] != '/' && k < pdates.length(); k++)
        bm = bm * 10 + pdates[k] - '0';
    if (pdates[k] == '/')
    {
        k++;
        bd = 0;
        for (; k < pdates.length(); k++)
            bd = bd * 10 + pdates[k] - '0';
    }
    else bd = 1;
    d[0] = by;
    d[1] = bm;
    d[2] = bd;
}
class InBook
{
public:
    //书类对象和书的数量
    Book* book;
    int bookcount;
    void write2Bookfile()//对书信息的操作函数
    {
        //书号、书名、作者、出版社、出版日期
        string num, title, author, publisher, pdates;
        Date pdate;
        int i, bd, bm, by, ct;
        float price;//价格
        ofstream outf("d:\\bookkk.txt", ios::out);
        //写入的文件名应该与读出的文件名相同；调试时可以取不同的文件名，以免覆盖掉原文件
        if (!outf)//判断是否成功打开
        {
            cerr << "File could not be open." << endl;
        }
        outf << "图书信息\n";//将引号内容写入文件
        for (int i = 0; i < bookcount; i++)
        {
            //获取所有书的信息并打印出来
            Date pd = book[i].getPublishdate();
            outf << book[i].getNum() << '\t' << book[i].getTitle() << '\t';
            outf << book[i].getAuthor() << '\t' << book[i].getPublisher() << '\t';
            outf << pd.getYear() << "/" << pd.getMonth() << "/" << pd.getDay();
            outf << '\t' << book[i].getPrice() << '\t' << book[i].getHowmany() << '\n';
        }
        outf.close();//关闭文件
    }
    int inbookFile(char* fileName, int delLine)//
    {
        //书号、书名、作者、出版社、出版日期
        string num, title, author, publisher, pdates;
        Date pdate;
        int i, bd, bm, by, ct;
        float price;//价格
        ifstream inf(fileName, ios::in);//加载文件
        if (!inf)//判断是否成功打开
        {
            cerr << "File could not be open." << endl;
            return 1;
        }
        char s[80];
        for (i = 1; i <= delLine; i++)
            inf.getline(s, 80);
        i = 0;
        //键入书籍信息
        while (!inf.eof())//  { inf.getline( s, 80 ) ;    cout << s << endl ;  }
        {
            inf.getline(s, 80, '\t');//num=s;
            inf.getline(s, 80, '\t');
            title = s;
            inf.getline(s, 80, '\t');//author=s;
            inf.getline(s, 80, '\t');//publisher=s;
            inf.getline(s, 80, '\t');//pdates=s;
            inf >> price >> ct;
            if (title.length() > 0)        i++;
        }
        bookcount = i;
        cout << bookcount << endl;//输出书的数量
        inf.clear();
        inf.seekg(0, ios::beg);//指针移到开头
        for (i = 1; i <= delLine; i++)
            inf.getline(s, 80);
        book = new Book[bookcount + INC];
        for (i = 0; i < bookcount; i++)
        {
            //键入书籍信息
            inf.getline(s, 80, '\t');
            num = s;
            inf.getline(s, 80, '\t');
            title = s;
            inf.getline(s, 80, '\t');
            author = s;
            inf.getline(s, 80, '\t');
            publisher = s;
            inf.getline(s, 80, '\t');
            pdates = s;
            inf >> price >> ct;//inf,getchar();
            if (title.length() > 0)
            {
                int d[3];
                if (num[0] == 10)num = num.substr(1);
                string2date(pdates, d);//格式化日期
                by = d[0];
                bm = d[1];
                bd = d[2];
                book[i] = Book();
                book[i].setNum(num);
                book[i].setTitle(title);
                book[i].setAuthor(author);
                book[i].setPublisher(publisher);
                book[i].setPrice(price);
                book[i].setHowmany(ct);
                book[i].setPublishdate(bd, bm, by);
            }
        }
        inf.close();//关闭文件
        return bookcount;
    }
    friend class ReaderBorrowBook;//声明友元类ReaderBorrowBook
    int addbook(string num, string title, string author, string publisher, int bd, int bm, int by, float price, int ct)
    {
        //添加书籍信息
        int i = bookcount;
        book[i] = Book();
        book[i].setNum(num);
        book[i].setTitle(title);
        book[i].setAuthor(author);
        book[i].setPublisher(publisher);
        book[i].setPrice(price);
        book[i].setHowmany(ct);
        book[i].setPublishdate(bd, bm, by);
        ++bookcount;
        return bookcount;
    }
    void searchbookbytitle(string title)//按书名查找书籍，找到返回书的信息，否则提示未找到
    {
        bool found = false;
        for (int i = 0; i < bookcount; i++)
            if ((book[i].getTitle()).find(title) != string::npos)
            {
                //cout<<book[i].getTitle()<< book[i].getTitle().find(title)<<endl;
                cout << i << "\t";
                book[i].dispABook();
                found = true;
                //return i;
            }
        if (!found)cout << "book title:" << title << " not found." << endl;
        //return -1;
    }
    int searchbookbytitlep(string title)//按书名查找书籍，找到返回书的信息和书的位置，否则提示未找到返回-1
    {
        for (int i = 0; i < bookcount; i++)
            if (book[i].getTitle() == title)
            {
                //cout<<book[i].getTitle()<< book[i].getTitle().find(title)<<endl;
                cout << i << "\t";
                book[i].dispABook();
                return i;
            }
        cout << "book title:" << title << " not found." << endl;
        return -1;
    }
    void searchbookbyauthor(string author)//按作者查找书籍，找到返回书的信息，否则提示未找到
    {
        bool found = false;
        for (int i = 0; i < bookcount; i++)
            if ((book[i].getAuthor()).find(author) != string::npos)
            {
                //cout<<book[i].getTitle()<< book[i].getTitle().find(title)<<endl;
                cout << i << "\t";
                book[i].dispABook();
                found = true;
                //return i;
            }
        if (!found)cout << "book author:" << author << " not found." << endl;
        //return -1;
    }
    int searchbookbyauthorp(string author)//按作者查找书籍，找到返回书的信息和书的位置，否则提示未找到返回-1
    {
        for (int i = 0; i < bookcount; i++)
            if (book[i].getAuthor() == author)
            {
                //cout<<book[i].getTitle()<< book[i].getTitle().find(title)<<endl;
                cout << i << "\t";
                book[i].dispABook();
                return i;
            }
        cout << "book author:" << author << " not found." << endl;
        return -1;
    }
    void searchbookbypub(string pub)//按出版社查找书籍，找到返回书的信息，否则提示未找到
    {
        bool found = false;
        for (int i = 0; i < bookcount; i++)
            if ((book[i].getPublisher()).find(pub) != string::npos)
            {
                //cout<<book[i].getTitle()<< book[i].getTitle().find(title)<<endl;
                cout << i << "\t";
                book[i].dispABook();
                found = true;
                //return i;
            }
        if (!found)cout << "book publisher:" << pub << " not found." << endl;
        //return -1;
    }
    int searchbookbypubp(string pub)//按出版社查找书籍，找到返回书的信息和书的位置，否则提示未找到返回-1
    {
        for (int i = 0; i < bookcount; i++)
            if (book[i].getPublisher() == pub)
            {
                //cout<<book[i].getTitle()<< book[i].getTitle().find(title)<<endl;
                cout << i << "\t";
                book[i].dispABook();
                return i;
            }
        return -1;
    }
    int searchbookbynum(string num)  //模糊查找包含num的串
    {
        bool found = false;
        for (int i = 0; i < bookcount; i++)
            if ((book[i].getNum()).find(num) != string::npos)
            {
                //cout<<book[i].getTitle()<< book[i].getTitle().find(title)<<endl;
                cout << i << "\t";
                book[i].dispABook();
                found = true;
                return i;
            }
        cout << "No num " << num << " existed." << endl;
        return -1;
    }
    int searchbookbynump(string num)  //精确查找等于num的串
    {
        for (int i = 0; i < bookcount; i++)
            if ((book[i].getNum()) == num)
            {
                //cout<<book[i].getTitle()<< book[i].getTitle().find(title)<<endl;
                cout << i << "\t";
                book[i].dispABook();
                return i;
            }
        return -1;
    }
    void sortbookbynum()//按书号排序
    {
        for (int i = 0; i < bookcount; i++)
        {
            int k = i;
            for (int j = i + 1; j < bookcount; j++)
                if (book[j].getNum() < book[k].getNum()) k = j;
            //cout<<k<<" k&i "<<i<<" :"<<book[i].getNum()<<"---"<<book[k].getNum()<<endl;
            if (k != i)
            {
                Book t = book[i];
                book[i] = book[k];
                book[k] = t;
            }
        }
    }
    void sortbookbytitle()//按标题排序
    {
        for (int i = 0; i < bookcount; i++)
        {
            int k = i;
            for (int j = i + 1; j < bookcount; j++)
                if (book[j].getTitle() < book[k].getTitle()) k = j;
            if (k != i)
            {
                Book t = book[i];
                book[i] = book[k];
                book[k] = t;
            }
        }
    }
    void changebookbynum(string oldnum, string newnum)//通过书号修改书
    {
        int k = searchbookbynump(oldnum);
        if (k >= 0)
        {
            book[k].setNum(newnum);
            cout << "changebookbynum successed:" << endl;
            book[k].dispABook();
        }
        else cout << "changebook failed. No book of num=" << oldnum << endl;
    }
    void deletebookbynum(string num)//通过书号删除书
    {
        int k = searchbookbynump(num);
        if (k >= 0)
        {
            cout << "Book to be deleted :" << endl;
            book[k].dispABook();
            book[k] = book[bookcount - 1];
            cout << "deletebookbynum successed:" << endl;
            bookcount--;
            //return bookcount;
        }
        else cout << "deletebook  failed. No book of num=" << num << endl;
    }

    void changebookbytitle(string oldtitle, string newtitle)//通过标题修改书
    {
        int k = searchbookbytitlep(oldtitle);
        if (k >= 0)
        {
            book[k].setTitle(newtitle);
            cout << "changebookbytitle successed:" << endl;
            book[k].dispABook();
        }
        else cout << "changebook failed. No book of title=" << oldtitle << endl;
    }

    void deletebookbytitle(string title)//通过标题删除书
    {
        int k = searchbookbytitlep(title);
        if (k >= 0)
        {
            cout << "Book to be deleted :" << endl;
            book[k].dispABook();
            book[k] = book[bookcount - 1];
            cout << "deletebookbytitle successed:" << endl;
            bookcount--;
            //return bookcount;
        }
        else cout << "deletebook  failed. No book of title=" << title << endl;

    }
};
class InReader
{
public:
    //读者类和读者人数
    Reader* reader;
    int readercount;
    void write2Readerfile()//对读者信息的操作函数
    {

    }
    int inreaderFile(char* fileName, int delLine)
    {
        //学号、姓名、学院、专业班级
        string num, name, college, classno;
        int i;
        //对文件的打开以及判断操作
        ifstream inf(fileName, ios::in);
        if (!inf)
        {
            cerr << "File could not be open." << endl;
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
        readercount = i;
        cout << readercount << endl;//输出读者数量
        inf.clear();
        inf.seekg(0, ios::beg);
        for (i = 1; i <= delLine; i++)
            inf.getline(s, 80);
        reader = new Reader[readercount + INC];
        for (i = 0; i < readercount; i++)
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
                reader[i] = Reader();
                reader[i].setNum(num);
                reader[i].setName(name);
                reader[i].setCollege(college);
                reader[i].setClassno(classno);
            }
        }
        inf.close();
        return readercount;

    }
    int addreader(string num, string name, string college, string classno)
    {
        //新增读者信息
        int i = readercount;
        reader[i] = Reader();
        reader[i].setNum(num);
        reader[i].setName(name);
        reader[i].setCollege(college);
        reader[i].setClassno(classno);

        ++readercount;
        return readercount;
    }
    void searchreaderbynum(string num)//通过学号查找读者，找到返回读者信息，否则提示未找到
    {
        bool found = false;
        for (int i = 0; i < readercount; i++)
            if ((reader[i].getNum()).find(num) != string::npos)
            {
                cout << i << "\t";
                reader[i].dispAReader();
                found = true;
                //return i;
            }
        if (!found)cout << "reader of num: " << num << " not found" << endl;
        //return -1;
    }
    int searchreaderbynump(string num)//通过学号查找读者，找到返回读者信息和位置，否则返回-1
    {
        for (int i = 0; i < readercount; i++)
            if (reader[i].getNum() == num)
            {
                cout << i << "\t";
                reader[i].dispAReader();
                return i;
            }
        return -1;
    }
    //自加函数。
    void searchreaderbyname(string name)//通过姓名查找读者，找到返回读者信息，否则提示未找到
    {
        bool found = false;
        for (int i = 0; i < readercount; i++)
            if ((reader[i].getName()).find(name) != string::npos)
            {
                cout << i << "\t";
                reader[i].dispAReader();
                found = true;
                //return i;
            }
        if (!found)cout << "reader of name: " << name << " not found" << endl;
        //return -1;
    }
    int searchreaderbynamep(string name)//通过姓名查找读者，找到返回读者信息和位置，否则返回-1
    {
        for (int i = 0; i < readercount; i++)
            if (reader[i].getName() == name)
            {
                cout << i << "\t";
                reader[i].dispAReader();
                return i;
            }
        return -1;
    }
    void searchreaderbyclassno(string classno)//通过班级查找读者，找到返回读者信息，否则提示未找到
    {
        bool found = false;
        for (int i = 0; i < readercount; i++)
            if ((reader[i].getClassno()).find(classno) != string::npos)
            {
                cout << i << "\t";
                reader[i].dispAReader();
                found = true;
                //return i;
            }
        if (!found)cout << "reader of classno: " << classno << " not found" << endl;
        //return -1;
    }
    int searchreaderbyclassnop(string classno)//通过班级查找读者，找到返回读者信息和位置，否则返回-1
    {
        for (int i = 0; i < readercount; i++)
            if (reader[i].getClassno() == classno)
            {
                cout << i << "\t";
                reader[i].dispAReader();
                return i;
            }
        return -1;
    }
    void sortreaderbynum()//按学号排序
    {
        for (int i = 0; i < readercount; i++)
        {
            int k = i;
            for (int j = i + 1; j < readercount; j++)
                if (reader[j].getNum() < reader[k].getNum()) k = j;
            //cout<<k<<" k&i "<<i<<" :"<<book[i].getNum()<<"---"<<book[k].getNum()<<endl;
            if (k != i)
            {
                Reader t = reader[i];
                reader[i] = reader[k];
                reader[k] = t;
            }
        }
    }
    void sortreaderbycollege()//按学院排序
    {
        for (int i = 0; i < readercount; i++)
        {
            int k = i;
            for (int j = i + 1; j < readercount; j++)
                if (reader[j].getCollege() < reader[k].getCollege()) k = j;
            //cout<<k<<" k&i "<<i<<" :"<<book[i].getNum()<<"---"<<book[k].getNum()<<endl;
            if (k != i)
            {
                Reader t = reader[i];
                reader[i] = reader[k];
                reader[k] = t;
            }
        }
    }
    void changereaderbynum(string oldnum, string newnum)//通过学号修改读者
    {
        int k = searchreaderbynump(oldnum);
        if (k >= 0)
        {
            reader[k].setNum(newnum);
            cout << "changereadernum successed:" << endl;
            reader[k].dispAReader();
        }
        else cout << "changereadernum failed. No reader of num=" << oldnum << endl;
    }
    void changereaderbyname(string oldname, string newname)//通过姓名修改读者
    {
        int k = searchreaderbynamep(oldname);
        if (k >= 0)
        {
            reader[k].setName(newname);
            cout << "changereadername successed:" << endl;
            reader[k].dispAReader();
        }
        else cout << "changereadername failed. No reader of name=" << oldname << endl;
    }
    void deletereaderbynum(string num)//通过学号删除读者
    {
        int k = searchreaderbynump(num);
        if (k >= 0)
        {
            cout << "Reader to be deleted :" << endl;
            reader[k].dispAReader();
            reader[k] = reader[readercount - 1];
            cout << "deletereadernum successed:" << endl;
            readercount--;
            //return readercount;
        }
        else cout << "deletenum  failed. No Reader of num=" << num << endl;
    }
    void deletereaderbyname(string name)//通过姓名删除读者
    {
        int k = searchreaderbynamep(name);
        if (k >= 0)
        {
            cout << "Reader to be deleted :" << endl;
            reader[k].dispAReader();
            reader[k] = reader[readercount - 1];
            cout << "deletereadername successed:" << endl;
            readercount--;
            //return readercount;
        }
        else cout << "deletename  failed. No Reader of name=" << name << endl;
    }
    friend class ReaderBorrowBook;//声明友元类ReaderBorrowBook
};
class InBorrowBook
{
public:
    //所借之书和借书数
    BorrowBook* borrowbook;
    int borrowbookcount;
    void write2BorrowBookfile()
    {

    }
    int inborrowbookFile(char* fileName, int delLine)
    {
        //对借书人以及所借之书的操作
        //学号、姓名、书号、书名、结束日期、应还日期、归还日期
        string num, name, booknum, title;
        string borrowdates;
        string toreturndates;
        string returndates;
        int i;
        //文件打开的常规操作
        ifstream inf(fileName, ios::in);
        if (!inf)
        {
            cerr << "File could not be open." << endl;
            return 1;
        }
        char s[80];
        for (i = 1; i <= delLine; i++)
            inf.getline(s, 80);
        i = 0;
        while (!inf.eof())
        {
            //从文件读入借书信息
            inf.getline(s, 80, '\t');
            inf.getline(s, 80, '\t');
            inf.getline(s, 80, '\t');
            inf.getline(s, 80);
            if (strlen(s) > 1)        i++;
        }
        borrowbookcount = i;
        cout << borrowbookcount << endl;//显示书籍数量
        inf.clear();
        inf.seekg(0, ios::beg);
        for (i = 1; i <= delLine; i++)
            inf.getline(s, 80);
        borrowbook = new BorrowBook[borrowbookcount + INC];
        for (i = 0; i < borrowbookcount; i++)
        {
            //从文件读入借书信息
            inf.getline(s, 80, '\t');
            num = s;
            inf.getline(s, 80, '\t');
            name = s;
            inf.getline(s, 80, '\t');
            booknum = s;
            inf.getline(s, 80, '\t');
            title = s;
            inf.getline(s, 80, '\t');
            borrowdates = s;
            inf.getline(s, 80, '\t');
            toreturndates = s;
            inf.getline(s, 80, '\n');
            returndates = s;
            if (name.length() > 0)
            {
                if (num[0] == 10)num = num.substr(1);
                borrowbook[i] = BorrowBook();
                int d[3];
                string2date(borrowdates, d);
                int by = d[0], bm = d[1], bd = d[2];
                borrowbook[i].setBorrowdate(bd, bm, by);
                string2date(toreturndates, d);
                by = d[0];
                bm = d[1];
                bd = d[2];
                borrowbook[i].setToreturndate(bd, bm, by);
                string2date(returndates, d);
                by = d[0];
                bm = d[1];
                bd = d[2];
                borrowbook[i].setReturndate(bd, bm, by);
                borrowbook[i].setNum(num);
                borrowbook[i].setName(name);
                borrowbook[i].setBookNum(booknum);
                borrowbook[i].setTitle(title);
            }
        }
        inf.close();

        return borrowbookcount;
    }
    friend class ReaderBorrowBook;//声明友元类ReaderBorrowBook
    int searchbyreaderbook(string readernum, string booknum)//按学号和书名查找信息，找到输出信息并返回位置，否则返回-1
    {
        for (int i = 0; i < borrowbookcount; i++)
            if ((borrowbook[i].getNum()) == readernum && (borrowbook[i].getBookNum()) == booknum)
            {
                cout << i << "\t";
                borrowbook[i].dispBorrowBook();
                return i;
            }
        return -1;

    }
    int searchbyreadernum(string readernum)//按学号查找信息
    {
        for (int i = 0; i < borrowbookcount; i++)
            if ((borrowbook[i].getNum()) == readernum)
            {
                cout << i << "\t";
                borrowbook[i].dispBorrowBook();
                return i;
            }
        cout << "No num " << readernum << " existed." << endl;
        return -1;
    }
    void searchbybooktitle(string booktitle)//按书名查找信息
    {
        for (int i = 0; i < borrowbookcount; i++)
            if ((borrowbook[i].getTitle()) == booktitle)
            {
                cout << i << "\t";
                borrowbook[i].dispBorrowBook();
                //return i;
            }
            else
            {
                cout << "No book named " << booktitle << endl;
            }
        //return -1;
    }
    int searchreaderbycollege(string college)//通过学院进行查询
    {
        for (int i = 0; i < borrowbookcount; i++)
            if (borrowbook[i].getCollege() == college)
            {
                cout << i << "\t";
                borrowbook[i].dispBorrowBook();
                return i;
            }
        cout << "No college " << college << " existed." << endl;
        return -1;

    }
};

class ReaderBorrowBook
{
    //书籍信息、读者信息、借书信息
    InBook bk;
    InReader rd;
    InBorrowBook bb;
public:
    void write2file()//对三个成员的操作
    {
        bk.write2Bookfile();
        rd.write2Readerfile();
        bb.write2BorrowBookfile();

    }
    void init()//设置需要加载的文件
    {
        bk.inbookFile("d:\\book.txt", 1);
        rd.inreaderFile("d:\\reader.txt", 1);
        bb.inborrowbookFile("d:\\borrowbook.txt", 1);
    }
    void dispBook()//显示图书信息
    {
        for (int i = 0; i < bk.bookcount; i++)
        {
            cout << i << ":";
            bk.book[i].dispABook();
        }
    }
    void dispReader()//显示读者信息
    {
        for (int i = 0; i < rd.readercount; i++)
        {
            cout << i << ":";
            rd.reader[i].dispAReader();
        }
    }
    void dispBorrowbook()//显示借书信息
    {
        for (int i = 0; i < bb.borrowbookcount; i++)
        {
            cout << i << ":";
            bb.borrowbook[i].dispBorrowBook();
        }
    }
    void dispCount()//显示书籍、读者、借书数量
    {
        cout << bk.bookcount << endl;
        cout << rd.readercount << endl;
        cout << bb.borrowbookcount << endl;
    }
    void addbook()//新增书籍函数
    {
        //书号、书名、作者、出版社
        string num, title, author, publisher;
        char num0[80], tit[80], auth[80], pub[80];
        //书籍日月年和馆存数量
        int pd, pm, py, howmany;
        float price;
        Date publishdate;
        cout << "书号、书名、作者、出版社、出版日期(yyyy mm dd)、定价、存馆数量" << endl;
        string num1 = "24416-5", title0 = "数据结构", author0 = "王红梅,胡明,王涛", pub0 = "清华大学出版社";
        int pd0 = 1, pm0 = 1, py0 = 2012;
        float price0 = 29.0;
        int howmany0 = 10;
        //bookcount=
        cout << "请输入书号、书名、作者、出版社、出版日期(yyyy mm dd)、定价、存馆数量：" << endl;
        cin >> num1 >> title0 >> author0 >> pub0 >> pd0 >> pm0 >> py0 >> price0 >> howmany0;
        bk.addbook(num1, title0, author0, pub0, pd0, pm0, py0, price0, howmany0);
        //新增书籍
        int i = bk.bookcount - 1;
        cout << i << ":";
        bk.book[i].dispABook();//输出书的信息
    }
    void addreader()//新增读者
    {
        //学号、姓名、学院、专业班级
        string num, name, college, classno;
        char num0[80], nam[80], coll[80], clas[80];
        cout << "学号\t姓名\t学院\t专业班级:" << endl;
        string num1 = "20151000", name0 = "王涛", college0 = "computer", class0 = "network class 1";
        cout << "请输入学号、姓名、学院、专业班级：" << endl;
        cin >> num1 >> name0 >> college0 >> class0;
        rd.addreader(num1, name0, college0, class0);
        //新增读者
        int i = rd.readercount - 1;
        cout << i << ":";
        rd.reader[i].dispAReader();//输出读者信息
    }
    void searchBook()//查找书籍，调用之前的函数
    {
        cout << "2．图书信息查询：分别按书名, 按作者名, 按出版社进行查询。" << endl;
        char tit[80];
        string title = "数据结构", author = "胡明", pub = "机械工业";
        int i, j, k, select;
        while (1)
        {
            cout << "图书信息查询：" << endl;
            cout << "1．按书名查询" << endl;
            cout << "2．按作者名查询" << endl;
            cout << "3．按出版社查询" << endl;
            cout << "0. return" << endl;
            cin >> select;
            cin.get();
            switch (select)
            {
            case 1:
                cout << "书名:";
                getline(cin, title, '\n');
                bk.searchbookbytitle(title);
                break;
            case 2:
                cout << "作者名:";
                getline(cin, author, '\n');
                bk.searchbookbyauthor(author);
                break;
            case 3:
                cout << "出版社:";
                getline(cin, pub, '\n');
                bk.searchbookbypub(pub);
                break;
            case 0:
                return;
            }
        }
    }
    void sortbook()//书籍排序，调用之前的函数
    {
        int select;
        cout << "3．图书信息排序：按书号、书名等按升序进行排序。" << endl;
        cout << "图书信息排序：" << endl;
        cout << "1．按书号排序" << endl;
        cout << "2．按书名排序" << endl;
        cout << "0. return" << endl;
        cin >> select;
        switch (select)
        {
        case 1:
            cout << "书号:";
            bk.sortbookbynum();
            dispBook();
            break;
        case 2:
            cout << "书名:";
            bk.sortbookbytitle();
            dispBook();
            break;
        case 0:
            return;
        }
    }
    void editbook()//改删书籍，调用之前的函数
    {
        string oldtitle = "VisualBasic 程序设计教程", newtitle = "VisualBasic 程序设计教程-C", oldnum = "40667", newnum = "40667-C";
        int select;
        cout << "4．图书信息的修改、删除：按书号或书名进行图书的修改和删除。" << endl;
        while (1)
        {
            cout << "图书信息的修改、删除：" << endl;
            cout << "1．按书号修改" << endl;
            cout << "2．按书号删除" << endl;
            cout << "3．按书名修改" << endl;
            cout << "4．按书名删除" << endl;
            cout << "0. return" << endl;
            cin >> select;
            cin.get();
            switch (select)
            {
            case 1:
                cout << "old书号:";
                getline(cin, oldnum, '\n');
                cout << "new书号:";
                getline(cin, newnum, '\n');
                cout << "changebookbynum: " << oldnum << " to " << newnum << endl;
                bk.changebookbynum(oldnum, newnum);
                //dispBook();
                break;
            case 2:
                cout << "delete书号:";
                getline(cin, oldnum, '\n');
                cout << "delete书号:" << oldnum << endl;
                bk.deletebookbynum(oldnum);
                //dispBook();
                break;
            case 3:
                cout << "old书名:";
                getline(cin, oldtitle, '\n');
                cout << "new书名:";
                getline(cin, newtitle, '\n');
                cout << "changebookbytitle: " << oldtitle << " to " << newtitle << endl;
                bk.changebookbytitle(oldtitle, newtitle);
                //dispBook();
                break;
            case 4:
                cout << "delete书名:";
                getline(cin, oldtitle, '\n');
                cout << "deletebookbytitle: " << oldtitle << endl;
                bk.deletebookbytitle(oldtitle);
                //dispBook();
                break;
            case 0:
                return;
            }
        }
    }
    void searchreader()//查找读者，调用之前的函数
    {
        cout << "6.读者信息查询：分别按学号、姓名、专业班级等进行查询。" << endl;
        char tit[80];
        string num = "20076954", name = "汤武", classno = "地信07-1";
        int i, j, k, select;
        while (1)
        {
            cout << "读者信息查询：" << endl;
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
                rd.searchreaderbynum(num);
                break;
            case 2:
                cout << "姓名:";
                getline(cin, name, '\n');
                rd.searchreaderbyname(name);
                break;
            case 3:
                cout << "专业班级:";
                getline(cin, classno, '\n');
                rd.searchreaderbyclassno(classno);
                break;
            case 0:
                return;
            }
        }
    }
    void sortreader()//读者信息排序，调用之前的函数
    {
        int select;
        cout << "7．读者信息排序：按学号、学院等按升序进行排序。" << endl;
        while (1)
        {
            cout << "读者信息排序：" << endl;
            cout << "1．按学号排序" << endl;
            cout << "2．按学院排序" << endl;
            cout << "0. return" << endl;
            cin >> select;
            switch (select)
            {
            case 1:
                cout << "学号:";
                rd.sortreaderbynum();
                dispReader();
                break;
            case 2:
                cout << "学院:";
                rd.sortreaderbycollege();
                dispReader();
                break;
            case 0:
                return;
            }
        }
    }
    void editreader()//改删读者，调用之前的函数
    {
        string oldnum = "20076954", newnum = "20076955", oldname = "汤武", newname = "谢本超", oldcollege = "资源与环境学院", newcollege = "资源与环境学院", oldclassno = "地信07-1", newclassno = "地信07-1";
        int select;
        cout << "8.读者信息的修改、删除：按学号+姓名进行读者信息的修改和删除。" << endl;
        while (1)
        {
            cout << "读者信息的修改、删除：" << endl;
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
                cout << "old学号:";
                getline(cin, oldnum, '\n');
                cout << "new学号:";
                getline(cin, newnum, '\n');
                cout << "changereaderbynum: " << oldnum << " to " << newnum << endl;
                rd.changereaderbynum(oldnum, newnum);
                //dispReader();
                break;
            case 2:
                cout << "delete学号:";
                getline(cin, oldnum, '\n');
                cout << "delete学号:" << oldnum << endl;
                rd.deletereaderbynum(oldnum);
                //dispReader();
                break;
            case 3:
                cout << "old姓名:";
                getline(cin, oldname, '\n');
                cout << "new姓名:";
                getline(cin, newname, '\n');
                cout << "changereaderbyname: " << oldname << " to " << newname << endl;
                rd.changereaderbyname(oldname, newname);
                //dispReader();
                break;
            case 4:
                cout << "delete姓名:";
                getline(cin, oldname, '\n');
                cout << "deletereaderbyname: " << oldname << endl;
                rd.deletereaderbyname(oldname);
                //dispReader();
                break;
            case 0:
                return;
            }
        }
    }
    void readerborrowabook()//图书借阅，调用之前的函数
    {
        cout << "9．图书借阅：输入学号+书号，如果该书图书信息表中的存馆数量大于0，则可以借出，\n" << "借出相应数量后修改图书信息表中的存馆数量，在图书借阅表添加该同学的借阅。" << endl;
        string rdnum = "20061709", booknum = "33071", name, title;
        int select, rdpos, bookpos, y, m, d;
        while (1)
        {
            cout << "图书借阅：" << endl;
            cout << "1．借书" << endl;
            cout << "0．return" << endl;
            cin >> select;
            cin.get();
            if (select == 0)return;
            cout << "borrow学号:";
            getline(cin, rdnum, '\n');
            cout << "borrow书号:";
            getline(cin, booknum, '\n');
            bookpos = bk.searchbookbynump(booknum);
            rdpos = rd.searchreaderbynump(rdnum);
            if (bookpos >= 0 && rdpos >= 0)
            {
                int hm = bk.book[bookpos].getHowmany();
                if (hm > 0)
                {
                    name = rd.reader[rdpos].getName();
                    title = bk.book[bookpos].getTitle();
                    bk.book[bookpos].setHowmany(hm - 1); //修改图书信息表中的存馆数量
                    bb.borrowbook[bb.borrowbookcount].setNum(rdnum);
                    bb.borrowbook[bb.borrowbookcount].setBookNum(booknum);
                    bb.borrowbook[bb.borrowbookcount].setName(name);
                    bb.borrowbook[bb.borrowbookcount].setTitle(title);

                    SYSTEMTIME ct;
                    GetLocalTime(&ct);//取系统时间，如果用GetSystemTime(&ct);那么获取的是格林尼治标准时间
                    y = ct.wYear;
                    m = ct.wMonth;
                    d = ct.wDay;
                    Date toret = Date(d, m, y) + 60;
                    bb.borrowbook[bb.borrowbookcount].setBorrowdate(d, m, y);
                    bb.borrowbook[bb.borrowbookcount].setToreturndate(toret.getDay(), toret.getMonth(), toret.getYear());
                    bb.borrowbook[bb.borrowbookcount].setReturndate(1, 1, 1);
                    bb.borrowbookcount++;
                }
                else cout << booknum << " 存馆数量=0" << ". can't be borrowed. " << endl;
            }
            else
            {
                if (bookpos < 0)cout << "No book " << booknum << ". can't borrow!" << endl;
                if (rdpos < 0)cout << "No reader " << rdnum << ". can't borrow!" << endl;
            }
        }
    }
    void readerreturnabook()//图书归还，调用之前的函数
    {
        cout << "10．图书归还：输入学号+书名，修改图书信息表中的存馆数量，图书借阅表中记录该同学的归还日期。" << endl;
        char tit[80];
        string rdnum = "20061709", booknum = "33071", name, title;
        int select, rdpos, bookpos, y, m, d;
        while (1)
        {
            cout << "图书归还：" << endl;
            cout << "1．还书" << endl;
            cout << "0．return" << endl;
            cin >> select;
            if (select == 0)return;
            cout << "return学号:";
            cin.getline(tit, 80);
            rdnum = tit;
            cout << "return书号:";
            cin.getline(tit, 80);
            booknum = tit;
            bookpos = bk.searchbookbynump(booknum);
            rdpos = rd.searchreaderbynump(rdnum);
            if (bookpos >= 0 && rdpos >= 0)
            {
                bk.book[bookpos].setHowmany(bk.book[bookpos].getHowmany() + 1);
                SYSTEMTIME ct;
                GetLocalTime(&ct);//取系统时间
                y = ct.wYear;
                m = ct.wMonth;
                d = ct.wDay;
                bb.borrowbook[bb.borrowbookcount].setReturndate(d, m, y);
            }
            else
            {
                if (bookpos < 0)cout << "No book " << booknum << ". can't return!" << endl;
                if (rdpos < 0)cout << "No reader " << rdnum << ". can't return!" << endl;
            }
        }
    }
    void searchreaderborrowbook()//图书查阅，调用之前的函数
    {
        int select;
        string num, name, college;
        cout << "11．图书借阅查询：分别按学号、书名、学院等进行查询。" << endl;
        while (1)
        {
            cout << "图书借阅查询：" << endl;
            cout << "1.按学号查询" << endl;
            cout << "2.按书号查询" << endl;
            cout << "3.按学院查询" << endl;
            cout << "0.return" << endl;
            cin >> select;
            cin.get();
            switch (select)
            {
            case 1:
                cout << "按学号查询:";
                getline(cin, num, '\n');
                bb.searchbyreadernum(num);
                break;
            case 2:
                cout << "按书名查询:";
                getline(cin, name, '\n');
                bk.searchbookbynum(name);
                break;
            case 3:
                cout << "按学院查询:";
                getline(cin, college, '\n');
                bb.searchreaderbycollege(college);
                break;
            case 0:
                return;
            }
        }

    }
};
int main()
{
    ReaderBorrowBook rbb;
    rbb.init();
    rbb.dispBook();
    rbb.dispReader();
    rbb.dispBorrowbook();
    rbb.dispCount();
    int select;
    while (1)
    {
        cout << "菜单选择功能：" << endl;
        cout << "1．图书信息添加功能：包括书号、书名、作者、出版社名称、存馆数量、定价等" << endl;
        cout << "2．图书信息查询：分别按书名, 按作者名, 按出版单位等进行查询。" << endl;
        cout << "3．图书信息排序：按书号、书名等按升序进行排序。" << endl;
        cout << "4．图书信息的修改、删除：按书号或书名进行图书的修改和删除。" << endl;
        cout << "5．读者信息添加功能：包括学号、姓名、学院、专业班级等。" << endl;
        cout << "6．读者信息查询：分别按学号、姓名、班级等进行查询。" << endl;
        cout << "7．读者信息排序：按学号、学院等按升序进行排序。" << endl;
        cout << "8．读者信息的修改、删除：按学号+姓名进行读者信息的修改和删除。" << endl;
        cout << "9．图书借阅：输入学号+书号，如果该书图书信息表中的存馆数量大于0，则可以借出," << endl;
        cout << "借出相应数量后修改图书信息表中的存馆数量，在图书借阅表添加该同学的借阅。" << endl;
        cout << "10．图书归还：输入学号+书名，修改图书信息表中的存馆数量，在图书借阅表中记录该同学的归还时间。" << endl;
        cout << "11．图书借阅查询：分别按学号、书名、学院等进行查询。" << endl;
        cout << "0.  exit" << endl;
        cin >> select;
        switch (select)
        {
        case 1:
            rbb.addbook();
            rbb.dispCount();
            break;
        case 2:
            rbb.searchBook();
            break;
        case 3:
            rbb.sortbook();
            break;
        case 4:
            rbb.editbook();
            break;
        case 5:
            rbb.addreader();
            rbb.dispCount();
            break;
        case 6:
            rbb.searchreader();
            break;
        case 7:
            rbb.sortreader();
            break;
        case 8:
            rbb.editreader();
            break;
        case 9:
            rbb.readerborrowabook();
            break;
        case 10:
            rbb.readerreturnabook();
            break;
        case 11:
            rbb.searchreaderborrowbook();
            break;
        case 0:
            rbb.write2file();
            exit(0);
        }
    }
    return 0;
}
