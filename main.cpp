
//Check the http_stuff for credits

#include <iostream>
#include "./http_stuff.h"
using namespace std;
int main(void) {
  cout << "Server waking up...";
  httplib::Server svr;

  //Get /, that is how the battlesnake engine will customize your snake.
  svr.Get("/", [](const auto &, auto &res) {
    string head = "default";  //TODO: Personalize
    string tail = "default";  //TODO: Personalize
    string author = "";       //TODO: Your Battlesnake Username
    string color = "#888888"; //TODO: Personalize (any hex color)
    res.set_content("{\"apiversion\":\"1\", \"head\":\"" + head + "\", \"tail\":\"" + tail + "\", \"color\":\"" + color + "\", " + "\"author\":\"" + author + "\"}", "text/json");
  });


  //Sent by the battlesnake engine when it needs you to move
  svr.Post("/move", [](auto &req, auto &res){
    //get json data
    string data = req.body;
    cout << "\n\n" + data;
    
    //TODO: Make some snake logic
    string moves[4] = {"up", "down", "left", "right"};
    int RandIndex = rand() % 4; //generates a random number between 0 and 3
    string move = moves[RandIndex];

    res.set_content("{\"move\": \"" + move + "\"}", "text/plain");
  });


  //Purely functional, useful if you have a stateful snake, you could do finalize work here
  svr.Post("/start", [](const auto &, auto &res){
    res.set_content("ok", "text/plain");
  });


   //Purely functional, useful if you have a stateful snake, you could do initialization work here
  svr.Post("/end", [](const auto &, auto &res){
    res.set_content("ok", "text/plain");
  });


  //Listen on host 0.0.0.0 and port 8080
  //Repl.it http servers will only run if the host is 0.0.0.0
  svr.listen("0.0.0.0", 8080);
}
