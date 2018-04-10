#pragma once
#include <vector>
using namespace std;

class Member{ 
    private:
        static int ACTIVE_MEMBERS; // counts current number of active members
        vector<Member *> followers; // holds the Members that follows you
        vector<Member *> following; // holds the Members you follow
    public:
        Member(); // empty constructor
        void follow(Member& m); // adds Member m to following vector and self to followers vector of m
        void unfollow(Member& m); // removes Member m from following vector and self from followers vector of m
        int numFollowers(); // returns number of followers
        int numFollowing(); // returns number of following
        static int count(); // returns number of current number of active members
        ~Member(); // destructor
};

