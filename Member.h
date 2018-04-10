#pragma once
#include <vector>
using namespace std;

class Member{
    private:
        static int NUMOFMEMBERS;
        vector<Member *> followers;
        vector<Member *> following;
    public:
        Member();
        void follow(Member& m); 
        void unfollow(Member& m);
        int numFollowers();
        int numFollowing();
        static int count();
        ~Member();
};

