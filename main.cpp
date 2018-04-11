#include "Member.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

    Member avi, beni, chana;

    void test(){
        Member david;
        avi.follow(david);
        CHECK(david.numFollowers() == 1);
        avi.follow(chana);
        CHECK(avi.numFollowing() == 3);
        avi.unfollow(beni);
        CHECK(avi.numFollowing() == 2);
        CHECK(Member::count() == 4);

    }

TEST_CASE("testing the follow function") {
    avi.follow(beni);
    CHECK(avi.numFollowing() == 1);
    CHECK(beni.numFollowers() == 1);
    avi.follow(beni); // should have no effect
    CHECK(avi.numFollowing() == 1);
    avi.follow(avi); // should have no effect
    CHECK(avi.numFollowing() == 1);
    avi.follow(chana);
    CHECK(avi.numFollowing() == 2);
    chana.follow(beni);
    CHECK(beni.numFollowers() == 2);
}

TEST_CASE("testing the unfollow function") {
    avi.unfollow(beni);
    CHECK(avi.numFollowing() == 1);
    CHECK(beni.numFollowers() == 1);
    avi.unfollow(beni); // should have no effect
    CHECK(avi.numFollowing() == 1);
    avi.unfollow(avi); // should have no effect
    CHECK(avi.numFollowing() == 1);
    avi.unfollow(chana);
    CHECK(avi.numFollowing() == 0);
    chana.unfollow(beni);
    CHECK(beni.numFollowers() == 0);
}

TEST_CASE("testing the count, constructor and destructor functions") {
    CHECK(Member::count() == 3);
    avi.follow(beni);
    test();
    CHECK(Member::count() == 3);
    CHECK(avi.numFollowing() == 1);
    CHECK(chana.numFollowers() == 1);
    avi.unfollow(chana);
    CHECK(avi.numFollowing() == 0);
}
