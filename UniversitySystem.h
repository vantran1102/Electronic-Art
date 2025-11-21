#ifndef UNIVERSITY_SYSTEM_H
#define UNIVERSITY_SYSTEM_H

#include <string>
#include <vector>
#include <list>

class Challange;
class Player;
class Badge;
class University;
class Match;

/*-------------------Player Class-------------------*/
class Player{
private:
    int totalScore;
    std::string name;
    std::vector<Badge>earnedBadges;
    University* currentUniversity;
public:
    Player(const std ::string& name);
    void earnBadge(Badge& badge);
    void startMatch(Match& match);
    void graduateUniversity(University* university);

    const std::string& getName() const;
    University* getCurrentUniversity() const;
    const std::vector<Badge*>& getBadges() const;
    int getStatScore() const;

};
/*--------------------Coach--------------------------*/
class Coach{
private:
    std::string name;
    std::string speciality;
    std::vector<std::string> dialogueLines;
public:
    Coach(const std::string& name, const std::string& speciality);
    void giveChallange(Challange& challange);
    void provideFeedback(Player& player);
    const std::string& getName() const;


};
/*---------------------------University---------------*/
class University{
private:
    std::string name;
    int difficultyLevel;
    int requireBadge;
    std::string theme;
    std::vector<Challange*> challange;
public:
    University(const std::string& name, int difficultyLevel);
    void assignChallange(Challange& challange);
    bool checkGraduation(Player& player) const;
    const std::string& getName() const;
    int getDifficultyLevel() const;

};
/*---------------------Badge-------------------------*/
class Badge{
private:
    std::string badgeName;
    std::string badgeType;
    bool earned;
    Challange* requirement;
    int rewardPoints;

public:
    Badge(const std::string& badgeName, 
                std::string& badgeType,
                int rewardPoints,
                Challange* requirement);
    void markAsEarned();
    const std::string& getName() const;
    bool isEarned() const;

};
/*---------------------Challange---------------------*/
class Challange{
private:
    std::string challangeName;
    int timeLimit;
    int progress;
    std::string goal;
public:
    Challange(const std::string& challangeName, int timeLimit, const std::string& goal);
    void updateProgress(int value);
    bool isCompleted() const;
    const std::string& getName() const;

};
/*---------------------Match-------------------------*/
class Match{
private:
    int matchID;
    std::vector<Player*> playersInMatch;
    std::string result;
public:
    Match(int matchID);
    void stimulateMatch();
    int getMatchID() const;
    int calculatePerformance(Player& player) const;
    const std::string& getResult() const;
};
/*------------------RewardSystem--------------------*/
class RewardSystem{
private:
    std::vector<Badge> availableRewards;
    std::vector<std::string> unlockConditions;
public:
    RewardSystem() = default;
    void grantReward(Player& player, const Badge& badge);
    std::vector<Badge> displayRewards() const;
    const std::vector<Badge*>& getAvailableRewards() const;
};
/*------------------LeaderBoard--------------------*/
class LeaderBoard{
private:
    std::list<Player*> playerRankings;
public:
    LeaderBoard() = default;
    void updateRankings(Player& player);
    std::vector<Player*> showTopPlayers(std::size_t count=10) const;
    std::list<Player*> getRanking(int n) const;
};
/*------------------Season--------------------*/
class Season{
private:
    int seasonScore;
    std::vector<Match> matches;
    University* currentUniversity;
public:
    Season(University* university);
    void addMatch(const Match& match);
    void calculateSeasonScore();
    int getSeasonScore() const;
};
/**/
#endif

