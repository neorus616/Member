#include "Member.h"
using namespace std;

int Member::ACTIVE_MEMBERS = 0;

Member::Member(){
    ACTIVE_MEMBERS++;
    }

void Member::follow(Member& m){
    if(this == &m)
        return;
    Member *mptr = &m;
    for(int i = 0; i<following.size(); i++)
        if(following[i] == mptr)
            return;
    following.push_back(mptr);
    mptr->followers.push_back(this);
}

void Member::unfollow(Member& m){
    if(this == &m)
        return;
    Member *mptr = &m;
    for(int i = 0; i<following.size(); i++)
        if(following[i] == mptr)
            following.erase(following.begin()+i);
    
    for(int i = 0; i<m.followers.size(); i++)
        if(m.followers[i] == this)
            m.followers.erase(m.followers.begin()+i);       
}

int Member::numFollowers(){
    return followers.size();
}

int Member::numFollowing(){
    return following.size();
}

int Member::count(){
    return ACTIVE_MEMBERS;
}


Member::~Member(){
    for(int i = 0; i<followers.size(); i++)
        (*followers[i]).unfollow(*this);
            
    for(int i = 0; i<following.size(); i++){
        unfollow(*following[i]);
    }
          ACTIVE_MEMBERS--;
}
