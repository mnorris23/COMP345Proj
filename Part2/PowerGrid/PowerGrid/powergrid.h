#pragma once

#include <string>
#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_window.H>
#include <FL/Fl_Button.H>
#include <FL/FL_Toggle_Button.H>
#include <FL/FL_Text_Display.H>
#include <FL/FL_Choice.H>
#include <FL/FL_Menu_Item.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Table.H>
#include <vector>

/** This class describes a City on the board.

*/
class City {
public:
	/**
		Default Constructor for a City. Not supposed to be used.
	*/
	City();
	/**
		Constructor Of a City for a City
		@param name The name of the city 
	*/
	City(std::string name);
	/**
		Default destructor
	*/
	~City();
	/**
		A setter method to set the name of a City.
		@param name The name of the City
	*/
	void setName(std::string name);
	/**
		A getter method for the name of a City.
		@return The name of a City
	*/
	std::string getName();
	/**
		A getter for the value to build a house on the City
		@return An int
	*/
	int getNextValue();
	/**
		Method will increment the value to build a house on the City by 5.
	*/
	void setNextvalue();
	/**
		Method to obtain the list of all cities connected to this City
		@return A vector of Cities
	*/
	std::vector<City> getConnectedTo();
	/**
		Add a city connection
		@param a The city to be connected with
		@param b The value of the connection
	*/
	void setConnectedTo(City a, int b);
	/**
		Get the list of values of connection with other cities
		@return A vector of int values
	*/
	std::vector<int> getConnectionValue();
	/**
		Set the value of a connection with a city
		Index is the same as vector connectedTo
		@param c The value of the connection
	*/
	void setConnectionValue(int c);
private:
	std::string name; 	///<The name of the City
	int nextValue;		///<The value to build a house on the City
	std::vector<City> connectedTo;		///<A Vector of Cities with which the city is connected to
	std::vector<int> connectionValue;	///<A Vector of Values for the connection with a city
};

/**
	This class describes a Power Plant card
*/
class PowerPlant {
public:
	/** 
		Default constructor. Not supposed to be used.
	*/
	PowerPlant();
	/** 
		Default destructor
	*/
	~PowerPlant();
	/** 
		The main constructor for a Power Plant
		@param val The value of the Power Plant
		@param consume The aumount of resources it consumes
		@param rtype The type of resources it consumes
		@param numCities The number of Cities it can power
	*/
	PowerPlant(int val, int consume, char rtype, int numCities);
	/** 
		Method to obtain the value of a Power Plant
		@return The value of the power plant
	*/
	int getValue();
	/** 
		Method to set the value of a Power Plant
		@param a The value of the power plant
	*/
	void setValue(int a);
	/** 
		Method to obtain the type of resource the power plant consumes
		@return A char representing the type of resource(s)
	*/
	char getResourceType();
	/** 
		Method to set the type of resources of a power plant
		@param c A char representing the type of resource(s)
	*/
	void setResourceType(char c);
	/** 
		Method to get the number of cities the power plant is able to provide with energy each turn
		@return The number of cities
	*/
	int getNumberOfCities();
	/** 
		Method to set the number of cities the power plant can provide in electricity
		@param num The number of cities
	*/
	void setNumberOfCities(int num);
private:
	int value; 				///<The value of the power plant
	char type;				///<The type of resources the power plant consumes
	int consumption;		///<The amount of resources the power plant consumes
	int numberOfResources;	///<The number of resources it currently has
	int numberOfCities;		///<The number of cities it can provide in energy
};

/** 
	This class describes all the possessions of a player	
*/
class Player {
public:
	/**
		The main constructor for a player
		@param name The name of the player
		@param color The color of the player
	*/
	Player(std::string name, int color);
	/**
		Another constructor. Not really used
		@param name The name of the player
	*/
	Player(std::string name);
	/** 
		The default constructor. Not used.
	*/
	Player();	
	/** 
		The defautlt destructor.
	*/
	~Player();	
	/** 
		Method to get the color of a player
		@return The color of the player
	*/
	std::string getColor();
	/** 
		Method to set the color of a player
		@param c The color of the player
	*/
	void setColor(std::string c);
	/** 
		Method to get the name of the player
		@return The name of the player
	*/
	std::string getName();
	/** 
		Method to set the name of the player
		@param name The name of the player
	*/
	void setName(std::string name);
	/** 
		Method to obtain the list of cities the player has a house on
		@return An pointer to an array of cities
	*/
	City* getCity();
	/** 
		Method to add a City to the list of cities the player has a house on
		@param e The city to add to the array
	*/
	void setCity(City* e);
	/** 
		Method to get the amount of money the player has
		@return The amount of money
	*/
	int getMoney();
	/** 
		Method to increment or decrement the money a player has
		@param a The value to increment of decrement
	*/
	void setMoney(int a);
	/** 
		Method to get the array of power plant the player currently owns
		@return The array of power plant
	*/
	PowerPlant* getPowerPlants();
	/** 
		Method to add a power plant to the array of a player
		@param plant The power plant to be added to the player
	*/
	void setPowerPlant(PowerPlant* plant);
	/** 
		Method to get the number of cities the player has currently a house on.
		@return The number of cities owned
	*/
	int getNumberOfCities();
	/** 
		Method to increment the number of cities owned by a player by one
	*/
	void setNumberOfCities();
	/** 
		Method to get the number of power plant the player has .
		@return The number of power plant owned
	*/
	int getNumberOfPowerPlant();
	/** 
		Method to increment the number of power plant owned by a player by one
	*/
	void setNumberOfPowerPlant();
	/** 
		Method to obtain all the relevant information about the possession of a player
		@return The name of the player, the number of cities he owns, the money he has, the power plant he owns
	*/
	std::string getPlayerInformation();
private:
	
	std::string color; 		///< The color of the player
	std::string name;		///< The name of the player
	City* cities[24];		///< The array of cities the player owns
	int money;				///< The amount of money the player has
	PowerPlant* power_plant[3];	///< The array of power plant the player owns
	int numberOfCities;			///< The number of cities the player owns
	int numberOfPowerPlant;		///< The number of power plant the player owns
};


/** 
		Class to display the relevant information about the different phases of the game
*/
class SummaryCard {
public:
	/**
		Default constructor
	*/
	SummaryCard();
	/**
		Default destructor
	*/
	~SummaryCard();
	/**
		Details of the first phase of a turn
		@return A string
	*/
	const char* firstPhase();
	/**
		Details of the second phase of a turn
		@return A string
	*/
	const char* secondPhase();
	/**
		Details of the third phase of a turn
		@return A string
	*/
	const char* thirdPhase();
	/**
		Details of the fourth phase of a turn
		@return A string
	*/
	const char* fourthPhase();
	/**
		Details of the fifth phase of a turn
		@return A string
	*/
	const char* fifthPhase();
	/**
		Method to combine the information about all the phases of the game.
		@return A string
	*/
	std::string allPhases();
	/**
		Method to create a string to display the amount of money the player will receive on the fifth phase of the game given the number of cities he currently has
		@param player The player 
		@return A string
	*/
	std::string payment(Player player);
};

/**
		Basic struct to contain the payment table
*/
struct Payment {
	static const unsigned int payment_table[21];
};


/**
	Class with only purpose is to contain a vector with all the players
*/
class PlayerVector {
public:
	/**
		Default constructor set the size of the vector to 2
	*/
	PlayerVector();
	/**
		Main constructor set the size of the vector given by the parameter
		@param size The size of the vector
	*/
	PlayerVector(int size);
	/**
		Default destructor
	*/
	~PlayerVector();
	/**
		Method to get to a specific player in the vector
		@param index The position of the player in the vector
		@return A player
	*/
	Player getPlayer(int index);
	/**
		Method to add a player to the vector
		@param p The player to add
		@param i The position of the player
	*/
	void setPlayer(Player p, int i);
private:
	int size;				///< The size of the vector of players
	std::vector<Player> arrayPlayer;	///< The vector of players
};

/**
	Class to define the main Window for the game.
*/
class StartGUI {
public:
	/**
		Default constructor
	*/
	StartGUI();
	/**
		Default destructor
	*/
	~StartGUI();
	/**
		CallBack method when pressing the two players button.
		@see twoplayers_cb_i
	*/
	static void twoplayers_cb(Fl_Widget*, void*);
	/**
		Method with only purpose is to hide and show some widget
	*/
	void twoplayers_cb_i(Fl_Widget*, void*);
	/**
		CallBack method when pressing the start button.
		@see start_cb_i
	*/
	static void start_cb(Fl_Widget*, void*);
	/**
		Method with only purpose is redirect to waitToStart() method
		@see waitToStart()
	*/
	void start_cb_i(Fl_Widget*, void*);
	/**
		Method to determine if the start button has been pressed
		@return value of button
	*/
	int getStartButtonValue();
	/**
		Method get the name for the first player from the input field
		@return name of button
	*/
	std::string getFirstPlayerName();
	/**
		Method get the name for the second player from the input field
		@return name of player
	*/
	std::string getSecondPlayerName();
	/**
		Method get the color for the first player from the dropdown box menu
		@return color of player
	*/
	int getFirstPlayerColor();
	/**
		Method get the color for the second player from the dropdown box menu
		@return color of player
	*/
	int getSecondPlayerColor();
	/**
		Method to obtain the information from the input field, create the players and add them to the vector of players.
		Also hide and show some widgets.
	*/
	void waitToStart();
	/**
		Method to diplay the information of the players to the corresponding widget
		@param list The vector of players
	*/
	void displayPlayerInformation(PlayerVector list);

private:
	Fl_Window* mainWindow;

	Fl_Text_Buffer *buff;
	Fl_Text_Display *welcome;
	Fl_Button* twoplayers;

	Fl_Toggle_Button* start;
	Fl_Input* first_player_name;
	Fl_Input* second_player_name;
	Fl_Choice* first_player_color;
	Fl_Choice* second_player_color;

	Fl_Text_Buffer *buffp1;
	Fl_Text_Display* infop1;
	Fl_Text_Buffer *buffp2;
	Fl_Text_Display* infop2;
	Fl_Text_Buffer *buffp3;
	Fl_Text_Display* infop3;
	Fl_Text_Buffer *buffp4;
	Fl_Text_Display* infop4;
	Fl_Text_Buffer *buffp5;
	Fl_Text_Display* infop5;
	Fl_Text_Buffer *buffp6;
	Fl_Text_Display* infop6;
	Fl_Text_Buffer *buff_summary;
	Fl_Text_Display* info_summary;


	Fl_Group* playerinfo;
	Fl_Group* map;
	Fl_Group* market;
	Fl_Group* resources;
	Fl_Group* summary;
	
};

