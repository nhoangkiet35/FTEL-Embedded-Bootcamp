#include <bits/stdc++.h>
using namespace std;

struct Student
{
    string name;
    string subject;
    char className;
    Student *next;
};

// === ONLY CODE WITHIN THE DESIGNATED AREA DO NOT MODIFY OTHER PARTS ===
Student *mergeExamLists(Student *mathList, Student *literatureList, Student *englishList, Student *physicsList)
{
    // Start your code here
    return 0;
}

// === DO NOT MODIFY OTHER PARTS ===
Student *makeNode(const string &name, const string &subject, char className)
{
    return new Student{name, subject, className, nullptr};
}

void appendNode(Student *&head, Student *&tail, Student *node)
{
    if (!head)
        head = tail = node;
    else
    {
        tail->next = node;
        tail = node;
    }
}

void buildList(int count, const string &subject, Student *&head, Student *&tail)
{
    for (int i = 0; i < count; i++)
    {
        string name;
        char className;
        if (!(cin >> name >> className))
            return;
        appendNode(head, tail, makeNode(name, subject, className));
    }
}

void printList(Student *head)
{
    while (head)
    {
        cout << head->name << "-" << head->subject << "-" << head->className;
        if (head->next)
            cout << "\n";
        head = head->next;
    }
}

int main()
{
    int m, l, e, p;
    if (!(cin >> m >> l >> e >> p))
        return 0;

    Student *mathHead = nullptr, *mathTail = nullptr;
    Student *litHead = nullptr, *litTail = nullptr;
    Student *engHead = nullptr, *engTail = nullptr;
    Student *phyHead = nullptr, *phyTail = nullptr;

    buildList(m, "toan", mathHead, mathTail);
    buildList(l, "van", litHead, litTail);
    buildList(e, "anh", engHead, engTail);
    buildList(p, "vatly", phyHead, phyTail);

    Student *res = mergeExamLists(mathHead, litHead, engHead, phyHead);
    cout << "\n__JUDGE_RESULT__\n";
    printList(res);
    return 0;
}