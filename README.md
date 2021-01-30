# A simple [Battlesnake](http://play.battlesnake.com) written in C++ with Replit.

This is a basic implementation of the [Battlesnake API](https://docs.battlesnake.com/snake-api). It's a great starting point for anyone wanting to program their first Battlesnake using C++. It comes ready to use with [Repl.it](https://repl.it) and provides instructions below for getting started.

### Technologies

* [C++](https://www.cplusplus.com/)
* [Repl.it](https://repl.it)


### Prerequisites

* [Battlesnake Account](https://play.battlesnake.com)
* [Repl.it Account](https://repl.it)
* [GitHub Account](https://github.com/) and [Git Command Line](https://www.atlassian.com/git/tutorials/install-git)  (optional)


## Running Your Battlesnake on [Repl.it](https://repl.it)

[![Run on Repl.it](https://repl.it/badge/DAChenScratch/Starter-Battlesnake-Cpp-with-replit)](https://repl.it/github/DAChenScratch/Starter-Battlesnake-Cpp-with-replit)

1. Login to your [Repl.it](https://repl.it) account.

2. Click the 'Run on Repl.it' button above, or visit the following URL: https://repl.it/github/DAChenScratch/Starter-Battlesnake-Cpp-with-replit.

3. You should see your Repl being initialized - this might take a few moments to complete.

4. Once your Repl is ready to run, click `Run ▶️` at the top of the screen.  Once C++ starting process is complete, your Battlesnake server will start and you should see the following:

    ```
       clang++-7 -pthread -std=c++17 -o main main.cpp; ./main
       Server waking up...
    ```

5. Above the terminal window you'll see the live output from your Battlesnake server, including its URL. That URL will be the URL used to create your Battlesnake in the next step. If you visit that URL in your browser, you should see text similar to this:

    ```
    {"apiversion":"1", "head":"default", "tail":"default", "color":"#888888", "author":""}
    ```

This means your Battlesnake is running correctly on Repl.it.

**At this point your Battlesnake is live and ready to enter games!**



## Customizing Your Battlesnake

Now you're ready to start customizing your Battlesnake's appearance and behavior.

### Changing Appearance

Locate the 'index' section inside [main.cpp](main.cpp#L11). You should see code that looks like this:
```cpp
    string head = "default";  //TODO: Personalize
    string tail = "default";  //TODO: Personalize
    string author = "";       //TODO: Your Battlesnake Username
    string color = "#888888"; //TODO: Personalize (any hex color)
    res.set_content("{\"apiversion\":\"1\", \"head\":\"" + head + "\", \"tail\":\"" + tail + "\", \"color\":\"" + color + "\", " + "\"author\":\"" + author + "\"}", "text/json");

```

This function is called by the game engine periodically to make sure your Battlesnake is healthy, responding correctly, and to determine how your Battlesnake will appear on the game board. See [Battlesnake Personalization](https://docs.battlesnake.com/references/personalization) for how to customize your Battlesnake's appearance using these values.

Whenever you update these values, you can refresh your Battlesnake on [your profile page](https://play.battlesnake.com/me/) to use your latest configuration. Your changes should be reflected in the UI, as well as any new games created.

### Changing Behavior

On every turn of each game your Battlesnake receives information about the game board and must decide its next move.

Locate the `move` section inside [main.cpp](main.cpp#L23). You should see code that looks like this:
```cpp
    //get json data
    string data = req.body;
    cout << "\n\n" + data;
    
    //TODO: Make some snake logic
    string moves[4] = {"up", "down", "left", "right"};
    int RandIndex = rand() % 4; //generates a random number between 0 and 3
    string move = moves[RandIndex];

    res.set_content("{\"move\": \"" + move + "\"}", "text/plain");
```

Possible moves are "up", "down", "left", or "right". To start your Battlesnake will choose a move randomly. Your goal as a developer is to read information sent to you about the board (available in the `data` variable) and make an intelligent decision about where your Battlesnake should move next. The request body is in string format. If you want a functioning std::map, go to: https://github.com/RyanFleck/cpp-snek for an awesome c++ battlesnake!

See the [Battlesnake Rules](https://docs.battlesnake.com/rules) for more information on playing the game, moving around the board, and improving your algorithm.

### Updating Your Battlesnake

After making changes to your Battlesnake, you can restart your Repl to have the change take effect (or in many cases your Repl will restart automatically).

Once the Repl has restarted you can [create a new game](https://play.battlesnake.com/account/games/create/) with your Battlesnake to watch your latest changes in action.

**At this point you should feel comfortable making changes to your code and starting new Battlesnake games to test those changes!**




## Developing Your Battlesnake Further

Now you have everything you need to start making your Battlesnake super smart! Here are a few more helpful tips:

* Keeping your Repl open in a second window while games are running is helpful for watching server activity and debugging any problems with your Battlesnake.

* The projected is configured with the error_log that you can use the code [cout]](https://www.cplusplus.com/reference/iostream/cout/) to output information to your server logs. This is very useful for debugging logic in your code during Battlesnake games.

* Review the [Battlesnake API Docs](https://docs.battlesnake.com/snake-api) to learn what information is provided with each command.

* When viewing a Battlesnake game you can pause playback and step forward/backward one frame at a time. If you review your logs at the same time, you can see what decision your Battlesnake made on each turn.



## Joining a Battlesnake Arena

Once you've made your Battlesnake behave and survive on its own, you can enter it into the [Global Battlesnake Arena](https://play.battlesnake.com/arena/global) to see how it performs against other Battlesnakes worldwide.

Arenas will regularly create new games and rank Battlesnakes based on their results. They're a good way to get regular feedback on how well your Battlesnake is performing, and a fun way to track your progress as you develop your algorithm.


### Questions?

All documentation is available at [docs.battlesnake.com](https://docs.battlesnake.com), including detailed Guides, API References, and Tips.

You can also join the Battlesnake Developer Community on [Discord](https://play.battlesnake.com/discord)  and [Slack](https://play.battlesnake.com/slack). We have a growing community of Battlesnake developers of all skill levels wanting to help everyone succeed and have fun with Battlesnake :)
