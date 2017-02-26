#include <iostream>
#include <map>
#include <vector>

/*
    Rubik's cube is modeled with two objects, the Cube
    and the Node. Each Node represents 1 block of a rubik's
    cube. The Node contains a map relating the direction of the
    face to the color of the face, along with methods to update
    the orientation of these colors.

    The Cube object contains a 3 dimensional array of nodes,
    with the (0,0,0) origin at the top left corner of the cube.
    There are methods to move the cube and to get a standard
    representation of the cube's state.

    the colors are represented by the characters and are
    initially set to the directions as follows

     N - NULL
     w - U
     r - R
     o - L
     y - D
     g - F
     b - B

    This notation for absolute cube direction also is
    used for turns. This notation will be used for
    function calls, for example L() is a 90* clockwise
    turn of the left face. See google for further notation
    info.

    NOTE: The way the cube is represented now, specifically
    because each face has the origin as its reference point,
    the orientation of the printed faces will appear different than
    what they would be if you were looking at a real Cube.
    This isn't a major issue as everything is still internally
    consistent, Will look into this more later.
*/

// map can't take arrays as container apparently, but can
// use vectors.
typedef std::vector< std::vector<char> > charArray;

class Node {

    public:
        /*
         * a map when initialized looks like
         *  {'U' : 'N', 'D' : 'N', 'F' : 'N', ... }
         *  All the directions start as N null color
         *  This is directly modified and called by
         *  Cube::populate() and Cube::getCube()
         */
        std::map<char, char> colorDat;
        Node(); // constructor
        void LRClock(); // Left/Right clockwise node shift
        void UDClock(); // Up/Down clockwise node shift
        void FBClock(); // Forward/Backward clockwise node shift
        //To replace the color data of a node.
        void setColors(std::map<char, char> cmap);
        //To get the color map of a node.
        std::map<char, char> getColors();
};

class Cube {
    /*
     *  The basic algorithim for the turns is
     *
     *  Node color shift for each node in slice
     *  take color data of said slice in 3x3 array
     *  put color data into each node 90* clockwise
     *
     *  see one of the turn functions (LR, UD, FB) for
     *  specifics.
     *
     *
     *  As of now there are 6 types of turns.
     *  From these we can compose other turns
     *  very simply, for example
     *  3 clockwise turns == 1 counterclockwise turn
     *  and so on.
     */
    private:
        //3d array of Node objects
        Node cubeArr[3][3][3];
        //Sets the colors to standard configuration, see above
        void populate();
        //These functions can be used for multiple turns
        //of the same type. LR(0) is the 0th index in the x
        //dimension of the cube, corresponding to the L Face.
        void LR(int index);
        void UD(int index);
        void FB(int index);
    public:
        //Constructor
        Cube();
        //outputs the cube as a map with directions
        //relating to 2d char array of each face.
        std::map<char, charArray> getCube();
        //The inverse of getCube, ability set the
        //cube to any configuration.
        void setCube(std::map<char, charArray> cubeMap);
        //Basic Cube turns.
        void L();
        void R();
        void U();
        void D();
        void F();
        void B();
        //Prints Cube::getCube() in a nice way, for testing.
        void printCube();
};
