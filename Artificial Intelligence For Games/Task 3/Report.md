### My CodinGame username: SWi
### Final rating: 621st place in Silver league, 1177th place in global leaderboard

The algorithm I've decided to use was simple BFS. Using this approach, I was looking for the potion I could brew in the least amount of turns. After that I would execute the first action on the path from the current state to the state returned by the BFS. Besides that, during the first 10 turns I would learn a free spell with probability 9/10 (with probability 1/10 I would run BFS).  The differences between my algorithm in wood, bronze and silver division were simply some bug fixes and taking into account new rules. 

Postmortem: https://www.codingame.com/forum/t/fall-challenge-2020-feedbacks-strategies/187846/122