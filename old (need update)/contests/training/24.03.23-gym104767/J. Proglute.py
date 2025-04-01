x = int(input())

print( ( pow( 2, (x-3) , int(1e9+7) ) *  x ) % int(1e9+7) )