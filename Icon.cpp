//IN THE FOLLOWING CODE FIND THE DEBT AND REFACTOR THE DESIGN
 
class Icon
{
    float speed, glow, energy;
    
    int movementType; // spinner, slider or hopper
 
    bool clockwise; // need for spinner
    bool expand; // need for spinner
    bool vertical; // need for slider
 
    int distance; // need for slider
    bool visible; // need for hopper
 
    int xcoord, ycoord; // need for hopper
 
    void spin() { }
 
    void slide() { }
 
    void hop() { }
    // constructor must set subtype: client must pass value
    public Icon(unsigned value)
    {
        movementType = value; // use enum for readability
        // and then use conditional to set associated fields
    }
    public void move()
    {
        if (movementType == 1) { spin(); }
        else if (movementType == 2)
        {
            slide();
        }
        else
        {
            hop();
        }
    }
// tedious subtype checking: subtype drives flair details
   public void flair()
   {
       if (movementType == 1) { spin(); }
       else if (movementType == 2)
       {
           slide();
       }
       else
       {
           hop();
       }
   }
}
