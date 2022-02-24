// #include "stdheaders.h"



class _Object
{
   
}


class Ground : _Object
{
public:
   
   static flt x, y, w, h;
   
   
   bool collidePlayer(Player p)
   {
      if(p.getRight() + 1 == T.x)
      {
         return true;
      }
      if(p.getLeft() - 1 == T.w)
      {
         return true;
      }
      if(p.getBottom() + 1 == T.y)
      {
         return true;
      }
      if(p.getTop() - 1 == T.h)
      {
         return true;
      }
      
      return false;
   }
   
   
}

class Player: _Object
{
public:

   static flt x;
   static flt y;
   static flt w;
   static flt h;
   
   // get the bottom of the player
   static flt getBottom()
   {
      return y + h;
   }
   
   static flt getTop()
   {
      return y;
   }
   
   static flt getLeft()
   {
      return x;
   }
   
   static flt getRight()
   {
      return x + w;
   }
   
}


// std::vector<Ground> platf;

Mems<Ground> platforms;

void InitPre()
{
   INIT();
}

bool Init()
{
   Player.x = 0;
   Player.y = 0;
   Player.w = 0.2;
   Player.h = 0.2;
   Ground g;
   g.x = 0.3;
   g.y = 0.3;
   g.w = 0.4;
   g.h = 0.4;
   // platf.push_back(g);
   
   platforms.add(g);
   
   return true;
}


void Shut()
{
   uint run = running;
}

Player player;

flt xVel = 0;
flt yVel = 0;

bool Update()
{
   static flt playerSpeed = 0.01;
   
   if(Kb.b(KB_A))
   {
      REPA(platforms)
   {
      if(!platforms[i].collidePlayer(player))
      {
         player.x -= xVel + playerSpeed;
      }
   }
      // Player.x -= xVel + playerSpeed;
   }
   
   if(Kb.b(KB_D))
   {
      // Player.x += xVel + playerSpeed;
      
      REPA(platforms)
   {
      if(!platforms[i].collidePlayer(player))
      {
         player.x += xVel + playerSpeed;
      }
   }
   }
   
   if(Kb.b(KB_W))
   {
      // Player.y += yVel + playerSpeed;
      
      REPA(platforms)
   {
      if(!platforms[i].collidePlayer(player))
      {
         player.y += yVel + playerSpeed;
      }
   }
   }
   
   if(Kb.b(KB_S))
   {
      // Player.y -= yVel + playerSpeed;
      
      REPA(platforms)
   {
      if(!platforms[i].collidePlayer(player))
      {
         player.y -= yVel + playerSpeed;
      }
   }
   }
   
   if(Kb.bp(KB_ESC))
   {
      return false;
   }
   return true;
}


void Draw()
{
   //Circle(0.2, player.x, player.y).draw(AZURE);
   
   D.clear(BLACK);
   
   Rect(player.x - (player.w / 2),  player.y - (player.h / 2),  player.x + player.w / 2, player.y + player.h / 2).draw(BLUE);
   
   REPA(platforms)
   {
      Rect(platforms[i].x, platforms[i].y, platforms[i].w, platforms[i].h).draw(YELLOW);
   }
   
}
