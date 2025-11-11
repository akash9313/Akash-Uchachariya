#include <bits/stdc++.h>
using namespace std;

class Participant{
    public:
    string name;
    string email;
    Participant(string n, string e){
        name = n;
        email = e;
    }

    void Participant_Display(){
        cout<<"Participant name : "<<name<<endl<<" email : "<<email<<endl;
    }
};

class Team{
    public:
    string teamname;
    string projecttitle;

    Team(string tn, string pt){
        teamname = tn;
        projecttitle = pt;
    }

    void Team_Display(){
        cout<<"Team name : "<<teamname<<endl<<" project title : "<<projecttitle<<endl;
    }
};

class ParticipantRecord : public Participant, public Team{
    public:
    ParticipantRecord(string n, string e, string tn, string pt) : Participant(n,e), Team(tn,pt) {}

    ParticipantRecord(const ParticipantRecord &pr):Participant(pr.name, pr.email), Team(pr.teamname, pr.projecttitle)
    {}

    void Display(){
        Participant_Display();
        Team_Display();
    }
};

int main(){
    ParticipantRecord p1("Akash", "abc@gmail.com", "Coders", "appdev");
    p1.Display();

    ParticipantRecord p2 = p1;
    cout<<endl<<"Using copy constructor : "<<endl;
    p2.Display();

    return 0;
}

