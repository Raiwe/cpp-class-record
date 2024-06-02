#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>


using namespace std;

struct Students {
    string IDnum, Name, Month, Day, Year, Address;
    int Math, English, Filipino, MAPEH, Science, Average;
};

void addRecord(struct Students students[], int l) {
    char name[50], month[9], day[3], year[5], address[50], idnum[10];

    for (int i = 0; i < l; i++) {
        if (students[i].IDnum == "\0") {
            cin.ignore();
            cout << "Student's name: ";
            cin.getline(name, 50);
            students[i].Name = name;
            cout << "Student's ID number: ";
            cin.getline(idnum, 10);
            students[i].IDnum = idnum;
            cout << "Input student's birthdate:\n";
            cout << "Month: ";
            cin.getline(month, 9);
            students[i].Month = month;
            cout << "day: ";
            cin.getline(day, 3);
            students[i].Day = day;
            cout << "Year: ";
            cin.getline(year, 5);
            students[i].Year = year;
            cout << "Student's address: ";
            cin.getline(address, 50);
            students[i].Address = address;
            break;
        }
    }
}

void editRecord(struct Students students[], string search, int l) {
    int choice, count = 0;
    char name[50], month[9], day[3], year[5], address[50], idnum[10];
    bool isTrue = true, isFalse = true;

    for (int i = 0; i < l; i++) {
        if (students[i].IDnum == search) {
            count++;
            do {
                system("cls");
                cout << "Choose what do you want to edit:" << endl;
                cout << "[1]ID number\n";
                cout << "[2]Name\n";
                cout << "[3]Birthdate\n";
                cout << "[4]Address\n";
                cout << "[5]Input other keys to exit\n";
                cout << "Choice: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        cin.ignore();
                        cout << "Input new ID number: ";
                        cin.getline(idnum, 10);
                        students[i].IDnum = idnum;
                        break;
                    case 2:
                        cin.ignore();
                        cout << "Input new name: ";
                        cin.getline(name, 50);
                        students[i].Name = name;
                        break;
                    case 3:
                        do {
                            system("cls");
                            cout << "Choose what do you want to edit:" << endl;
                            cout << "[1]Month\n";
                            cout << "[2]Day\n";
                            cout << "[3]Year\n";
                            cout << "[4]Input other keys to exit\n";
                            cout << "Choice: ";
                            cin >> choice;

                            switch (choice) {
                                case 1:
                                    cin.ignore();
                                    cout << "Input new month: ";
                                    cin.getline(month, 9);
                                    students[i].Month = month;
                                    break;
                                case 2:
                                    cin.ignore();
                                    cout << "Input new day: ";
                                    cin.getline(day, 3);
                                    students[i].Day = day;
                                    break;
                                case 3:
                                    cin.ignore();
                                    cout << "Input new year: ";
                                    cin.getline(year, 5);
                                    students[i].Year = year;
                                    break;
                                default:
                                    isFalse = false;
                            }
                        }while (isFalse != false);
                        break;
                    case 4:
                        cin.ignore();
                        cout << "Input new address: ";
                        cin.getline(address, 50);
                        students[i].Address = address;
                        break;
                    default:
                        isTrue = false;
                }
            }while (isTrue != false);
        }
    }
    if (count == 0) {
        cout << "ID number does not exist!" << endl;
    }
}

void inputeditGrades(struct Students students[], string search, int l) {
    int choice, count = 0;

    for (int i = 0; i < l; i++) {
        if (students[i].IDnum == search) {
            count++;
            cout << "Choose what subject:" << endl;
            cout << "[1]Math\n";
            cout << "[2]English\n";
            cout << "[3]Filipino\n";
            cout << "[4]MAPEH\n";
            cout << "[5]Science\n";
            cout << "Choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "input/edit math grade: ";
                    cin >> students[i].Math;
                    break;
                case 2:
                    cout << "input/edit english grade: ";
                    cin >> students[i].English;
                    break;
                case 3:
                    cout << "input/edit filipino grade: ";
                    cin >> students[i].Filipino;
                    break;
                case 4:
                    cout << "input/edit mapeh grade: ";
                    cin >> students[i].MAPEH;
                    break;
                case 5:
                    cout << "input/edit science grade: ";
                    cin >> students[i].Science;
                    break;
                default: cout << "Invalid input!" << endl;
                system("pause");
                system("cls");
                inputeditGrades(students, search, l);
            }
        }
    }
    if (count == 0) {
        cout << "ID number does not exist!" << endl;
    }
}

bool compareName(Students a, Students b) {
    if (a.Name < b.Name) {
        return 1;
    }
    else {
        return 0;
    }
}

bool compareAverage(Students a, Students b) {
    if (a.Average > b.Average) {
        return 1;
    }
    else {
        return 0;
    }
}

void viewRecord(struct Students students[], int l) {
    int count = 0;

    sort(students, students + l, compareName);

    cout << setw(4) << left << "No." << setw(10) << left << "ID no." << setw(30) << left << "Name" << endl;

    for (int i = 0; i < l; i++) {
        if (students[i].IDnum != "\0") {
            count++;
            cout << setw(4) << left << count << setw(10) << left << students[i].IDnum << setw(30) << left << students[i].Name << endl;
        }
    }
}

void viewbestin(struct Students students[], int choice, int l) {
    int highestgrade = 0;
    string beststudent;

    switch (choice) {
        case 1:
            for (int i = 0; i < l; i++) {
                if (students[i].IDnum != "\0") {
                    if (students[i].Math > highestgrade) {
                    highestgrade = students[i].Math;
                    beststudent = students[i].Name;
                }  
                }
            }

            cout << "The best student in math is " <<  beststudent << " with the grade of " << highestgrade << endl;
            system("pause");
            system("cls");
            break;
        case 2:
            highestgrade = 0;
            beststudent = " ";

            for (int i = 0; i < l; i++) {
                if (students[i].IDnum != "\0") {
                    if (students[i].English > highestgrade) {
                    highestgrade = students[i].English;
                    beststudent = students[i].Name;
                } 
                } 
            }

            cout << "The best student in english is " <<  beststudent << " with the grade of " << highestgrade << endl;
            system("pause");
            system("cls");
            break;
        case 3:
            highestgrade = 0;
            beststudent = " ";

            for (int i = 0; i < l; i++) {
                if (students[i].IDnum != "\0") {
                    if (students[i].Filipino > highestgrade) {
                    highestgrade = students[i].Filipino;
                    beststudent = students[i].Name;
                } 
                } 
            }

            cout << "The best student in filipino is " <<  beststudent << " with the grade of " << highestgrade << endl;
            system("pause");
            system("cls");
            break;
        case 4:
            highestgrade = 0;
            beststudent = " ";

            for (int i = 0; i < l; i++) {
                if (students[i].IDnum != "\0") {
                    if (students[i].MAPEH > highestgrade) {
                    highestgrade = students[i].MAPEH;
                    beststudent = students[i].Name;
                } 
                } 
            }

            cout << "The best student in mapeh is " <<  beststudent << " with the grade of " << highestgrade << endl;
            system("pause");
            system("cls");
            break;
        case 5:
            highestgrade = 0;
            beststudent = " ";

            for (int i = 0; i < l; i++) {
                if (students[i].IDnum != "\0") {
                    if (students[i].Science > highestgrade) {
                    highestgrade = students[i].Science;
                    beststudent = students[i].Name;
                } 
                } 
            }

            cout << "The best student in science is " <<  beststudent << " with the grade of " << highestgrade << endl;
            system("pause");
            system("cls");
            break;
    }
}

void viewgradebook(struct Students students[], int l) {
    int count = 0, sum;

    for (int i = 0; i < l; i++) {
        if (students[i].IDnum != "\0") {
            sum = students[i].Math + students[i].English + students[i].Filipino + students[i].MAPEH + students[i].Science;
            students[i].Average = sum / 5;
        }
    }

    sort(students, students + l, compareAverage);

    cout << setw(4) << left << "No." << setw(10) << left << "ID no." << setw(30) << left << "Name" << setw(5) << left << "Math" << setw(8) << left << "English" << setw(9) << left << "Filipino" << setw(6) << left << "MAPEH" << setw(8) << left << "Science" << setw(8) << left << "Average" << endl;


    for (int i = 0; i < l; i++) {
        if (students[i].IDnum != "\0") {
            count++;
            cout << setw(4) << left << count << setw(10) << left << students[i].IDnum << setw(30) << left << students[i].Name << setw(5) << left << students[i].Math << setw(8) << left << students[i].English << setw(9) << left << students[i].Filipino << setw(6) << left << students[i].MAPEH << setw(8) << left << students[i].Science << setw(8) << left << students[i].Average <<endl;
        }
    }
}

void printstudentsRecord(struct Students students[], string search, int l) {
    int count = 0;
    string myText;
    
    cout << setw(4) << left << "No." << setw(10) << left << "ID no." << setw(30) << left << "Name" << setw(5) << left << "Math" << setw(8) << left << "English" << setw(9) << left << "Filipino" << setw(6) << left << "MAPEH" << setw(8) << left << "Science" << setw(8) << left << "Average" << endl;

    for (int i = 0; i < l; i++) {
        if (students[i].IDnum == search) {
            ofstream printer;
            printer.open("Student Record.txt", ios::app);
            count++;
            printer << setw(4) << left << count << setw(10) << left << students[i].IDnum << setw(30) << left << students[i].Name << setw(5) << left << students[i].Math << setw(8) << left << students[i].English << setw(9) << left << students[i].Filipino << setw(6) << left << students[i].MAPEH << setw(8) << left << students[i].Science << setw(8) << left << students[i].Average <<endl;
            printer.close();

            ifstream reader;
            reader.open("Student Record.txt", ios::app);
            while (getline(reader, myText)) {
                cout << myText << endl;
            }
            break;
        }
    }
    if (count == 0) {
        cout << "ID number does not exist!" << endl;
    }
}

bool compareMath(Students a, Students b) {
    if (a.Math > b.Math) {
        return 1;
    }
    else {
        return 0;
    }
}

bool compareEnglish(Students a, Students b) {
    if (a.English > b.English) {
        return 1;
    }
    else {
        return 0;
    }
}

bool compareFilipino(Students a, Students b) {
    if (a.Filipino > b.Filipino) {
        return 1;
    }
    else {
        return 0;
    }
}

bool compareMAPEH(Students a, Students b) {
    if (a.MAPEH > b.MAPEH) {
        return 1;
    }
    else {
        return 0;
    }
}

bool compareScience(Students a, Students b) {
    if (a.Science > b.Science) {
        return 1;
    }
    else {
        return 0;
    }
}

void printclassRecord(struct Students students[], int l) {
    ofstream printer;
    printer.open("Class Record.txt", ios::trunc);

    int count = 0;

    sort(students, students + l, compareMath);
    sort(students, students + l, compareEnglish);
    sort(students, students + l, compareFilipino);
    sort(students, students + l, compareMAPEH);
    sort(students, students + l, compareScience);

    printer << setw(4) << left << "No." << setw(10) << left << "ID no." << setw(30) << left << "Name" << setw(5) << left << "Math" << endl;
    for (int i = 0; i < l; i++) {
        if (students[i].IDnum != "\0") {
            count++;
            printer << setw(4) << left << count << setw(10) << left << students[i].IDnum << setw(30) << left << students[i].Name << setw(5) << left << students[i].Math << endl;
        }
    }
    
    count = 0;
    printer << setw(4) << left << "No." << setw(10) << left << "ID no." << setw(30) << left << "Name" << setw(5) << left << "English" << endl;
    for (int i = 0; i < l; i++) {
        if (students[i].IDnum != "\0") {
            count++;
            printer << setw(4) << left << count << setw(10) << left << students[i].IDnum << setw(30) << left << students[i].Name << setw(5) << left << students[i].English << endl;
        }
    }

    count = 0;
    printer << setw(4) << left << "No." << setw(10) << left << "ID no." << setw(30) << left << "Name" << setw(5) << left << "Filipino" << endl;
    for (int i = 0; i < l; i++) {
        if (students[i].IDnum != "\0") {
            count++;
            printer << setw(4) << left << count << setw(10) << left << students[i].IDnum << setw(30) << left << students[i].Name << setw(5) << left << students[i].Filipino << endl;
        }
    }

    count = 0;
    printer << setw(4) << left << "No." << setw(10) << left << "ID no." << setw(30) << left << "Name" << setw(5) << left << "MAPEH" << endl;
    for (int i = 0; i < l; i++) {
        if (students[i].IDnum != "\0") {
            count++;
            printer << setw(4) << left << count << setw(10) << left << students[i].IDnum << setw(30) << left << students[i].Name << setw(5) << left << students[i].MAPEH << endl;
        }
    }

    count = 0;
    printer << setw(4) << left << "No." << setw(10) << left << "ID no." << setw(30) << left << "Name" << setw(5) << left << "Science" << endl;
    for (int i = 0; i < l; i++) {
        if (students[i].IDnum != "\0") {
            count++;
            printer << setw(4) << left << count << setw(10) << left << students[i].IDnum << setw(30) << left << students[i].Name << setw(5) << left << students[i].Science << endl;
        }
    }
    printer.close();

    string myText;

    ifstream reader;
    reader.open("Class Record.txt");
    while (getline(reader, myText)) {
        cout << myText << endl;
    }
}

int main() {
    struct Students students[50];

    int entry, l = sizeof(students)/sizeof(students[0]);
    bool isTrue = true;
    string idnum;

    while (isTrue) {
        cout << "Class Record" << endl;
        cout << "[1]Add student\n";
        cout << "[2]Edit student record\n";
        cout << "[3]Input/Edit Grades\n";
        cout << "[4]View class record\n";
        cout << "[5]View best in\n";
        cout << "[6]View grade book\n";
        cout << "[7]Print document (student record)\n";
        cout << "[8]Print document (class record)\n";
        cout << "[9]Input other keys to exit\n";
        cout << "Entry: ";
        cin >> entry;

        switch (entry) {
            case 1:
                addRecord(students, l);
                system("cls");
                break;
            case 2:
                cout << "Search by student's ID number: ";
                cin >> idnum;
                editRecord(students, idnum, l);
                system("pause");
                system("cls");
                break;
            case 3:
                cout << "Search by student's ID number: ";
                cin >> idnum;
                inputeditGrades(students, idnum, l);
                system("cls");
                break;
            case 4:
                viewRecord(students, l);
                system("pause");
                system("cls");
                break;
            case 5:
                int choice;

                cout << "Choose what subject:" << endl;
                cout << "[1]Math\n";
                cout << "[2]English\n";

                cout << "[3]Filipino\n";
                cout << "[4]MAPEH\n";
                cout << "[5]Science\n";
                cin >> choice;
                viewbestin(students, choice, l);
                break;
            case 6:
                viewgradebook(students, l);
                system("pause");
                system("cls");
                break;
            case 7:
                cout << "Search by student ID number: ";
                cin >> idnum;
                printstudentsRecord(students, idnum, l);
                system("pause");
                system("cls");
                break;
            case 8:
                printclassRecord(students, l);
                system("pause");
                system("cls");
                break;
            default: isTrue = false;
        }
    }
    return 0;
}