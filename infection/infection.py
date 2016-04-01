# Khan Academy
# Infection
# Author: Daniel Lu

"""
    Here's what I'm thinking for the classroom / user model.
    A classroom is a collection of users.  There's nothing else in particular that a
    classroom seems to need, so we'll use an array.  Each user is identified by its array index.

    A user has identification, infection version, and its coaching relations.

    Since we have both 'coached by' and 'coaches' relations, and A is coached by B if B coaches A,
    we can treat this as just a single 'connection' relation.  Goes both ways, and now we have an
    undirected graph I guess.  So, a User:
"""


class User:
    """ A user.  Has ID, infection version, list of connections.
    Can coach other users """
    def __init__(self, ident, infection):
        self.ident, self.infection = ident, infection
        self.connections = []
        self.hit = 0

    def get_id(self):
        return self.ident

    """ We just return status codes here
        since I don't really want User to decide what
        to do about different version numbers. """

    def coach(self, student):
        self.connections.append(student)
        student.connections.append(self)

        if self.infection == student.infection:
            """ do nothing code """
            return 0

        elif self.infection > student.infection:
            """ infect student code """
            return 1

        elif self.infection < student.infection:
            """ infect self code """
            return -1


def total_infection(user, infection_ver):
    user.infection = infection_ver

    for stud in user.connections:

        if user.infection < stud.infection:
            """ It seems like a bad idea to downgrade a student's version.
                So instead we upgrade the entire graph to the highest version found """
            total_infection(user, stud.infection)

        elif user.infection > stud.infection:
            total_infection(stud, user.infection)


"""
    Here's what I'm thinking for limited_infection.
    First of all, I don't want to infect over the desired number given.
    Because it's a lot of trouble to decide what a reasonable upper limit should be.

    Second of all, I don't allow a starting user to be specified.
    As far as I can tell right now, it's easier to control the number of
    users that do get infected this way.  And that seems to be the point of
    limited_infection.

    The idea:
    We do something similar to infect, but instead of infecting,
    we produce a "number of users possible to reach" for each user
    and stick that in a tuple with the user and stick the tuples in
    a list.

    Then, we sort the list by that number, and infect the user
    associated with the largest number smaller than the desired number.
    If we find a suitable user, we subtract its number of reachable users
    from the num_to_infect.

    We repeat the process, skipping over users that are in the previous
    user's connections list.

    If there are no more suitable users, we just decide to be satisfied with that.
"""


def limited_infection(classroom, num_to_infect, infection_ver):
    limit = num_to_infect
    countlst = []
    for user in classroom:
        countlst.append((user, count_reachable(user, Counter())))
        for i in range(len(classroom)):
            classroom[i].hit = 0

    sortedcountlst = sorted(countlst, key=lambda cnt: cnt[1])

    prev = None
    for usertup in reversed(sortedcountlst):
        if usertup[1] <= limit:
            if prev is None or usertup[0] not in prev.connections:
                total_infection(usertup[0], infection_ver)
                prev = usertup[0]
                limit -= usertup[1]
        if limit <= 0:
            break
    return classroom


class Counter:
    pass
    count = 0


def count_reachable(user, counter):
    user.hit = 1
    counter.count += 1
    for stud in user.connections:
        if user.hit != stud.hit:
            count_reachable(stud, counter)
    return counter.count


def test():
    """A set of unit tests"""
    khanclass = [User(ident, 0) for ident in range(6)]

    """ basic relation, infection test. """
    assert(khanclass[1].coach(khanclass[3]) == 0)
    assert(khanclass[1].coach(khanclass[5]) == 0)
    total_infection(khanclass[1], 1)

    assert(khanclass[0].infection == 0)
    assert(khanclass[1].infection == 1)
    assert(khanclass[2].infection == 0)
    assert(khanclass[3].infection == 1)
    assert(khanclass[4].infection == 0)
    assert(khanclass[5].infection == 1)

    """ Adding a new relation and seeing what happens
        if we try to downgrade users 1,3,5 back down to 0 version """
    assert(khanclass[2].coach(khanclass[3]) == -1)
    total_infection(khanclass[2], 0)

    """ User 2 should have upgraded to the same version as user 3
        since it tries to downgrade user 3.  User 0,1,3,4,5 should be
        unaffected """

    assert(khanclass[0].infection == 0)
    assert(khanclass[1].infection == 1)
    assert(khanclass[2].infection == 1)
    assert(khanclass[3].infection == 1)
    assert(khanclass[4].infection == 0)
    assert(khanclass[5].infection == 1)

    assert(khanclass[0].coach(khanclass[4]) == 0)

    """ Testing the last coach case, and a whole graph update """
    assert(khanclass[5].coach(khanclass[4]) == 1)

    total_infection(khanclass[4], 2)

    for i in range(6):
        assert(khanclass[i].infection == 2)

    print("All tests pass")


def test2():
    """ A test for limited_infection
        Users begin with version 0.
        The specified number of users should end with version 1. """

    khanclass2 = [User(ident, 0) for ident in range(10)]

    """ Some tests for reachable counts of users """
    khanclass2[0].coach(khanclass2[1])
    khanclass2[1].coach(khanclass2[2])
    khanclass2[2].coach(khanclass2[3])

    khanclass2[5].coach(khanclass2[6])
    khanclass2[6].coach(khanclass2[7])
    khanclass2[7].coach(khanclass2[8])

    count = count_reachable(khanclass2[0], Counter())
    count2 = count_reachable(khanclass2[5], Counter())

    assert(count == 4)
    assert(count2 == 4)

    for i in range(10):
        khanclass2[i].hit = 0

    khanclass2[8].coach(khanclass2[0])
    count3 = count_reachable(khanclass2[3], Counter())
    assert(count3 == 8)

    for i in range(10):
        khanclass2[i].hit = 0

    khanclass3 = [User(ident, 0) for ident in range(10)]

    """ 1 reached """
    khanclass3[0].coach(khanclass3[1])
    khanclass3[1].coach(khanclass3[2])
    khanclass3[2].coach(khanclass3[3])

    khanclass3[5].coach(khanclass3[6])
    khanclass3[6].coach(khanclass3[7])
    khanclass3[7].coach(khanclass3[8])

    """ 2 reached """
    khanclass3[4].coach(khanclass3[9])

    """ Testing with a desired number of 7 """

    khanclasstemp = limited_infection(khanclass3, 7, 1)
    print("There should be close to 7 users with version 1")
    print("There are: ")

    count = 0
    for user in khanclasstemp:
        if user.infection == 1:
            count += 1

    print(count)
    print()
    for user in khanclasstemp:
        print("User %i has version: %i" % (user.get_id(), user.infection))

    print()
    print("This is not well tested though.")
    print("The combination of 4 reachable users and 2 reachable users happens to be lucky.")


def main():
    test()
    print()
    print("******************************")
    print()
    test2()

if __name__ == "__main__":
    main()
