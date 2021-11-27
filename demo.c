
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
//#include "luaconfig.h"
#include <stdio.h>


static int sqr(lua_State *L){              /* Internal name of func */
//      float val = lua_tonumber(L, -1);
        float val=luaL_checknumber(L,1);                                /* Get the single number arg */
        printf("square, nbr=%f\n",val);
        lua_pushnumber(L,val*val);           /* Push the return */
        return 1;                              /* One return value */
}
static int cub(lua_State *L){                /* Internal name of func */
        float val = lua_tonumber(L, -1);      /* Get the single number arg */
        printf("cube, number=%f\n",val);
        lua_pushnumber(L,val*val*val);      /* Push the return */
        return 1;                              /* One return value */
}

int luaopen_(lua_State *L){
        lua_register(
                        L,               /* Lua state variable */
                        "square",        /* func name as known in Lua */
                        sqr          /* func name in this file */
                        );
        lua_register(L,"cube",cub);
        return 0;
}
