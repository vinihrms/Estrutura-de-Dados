// TAD: Point (x, y)
typedef struct point Point;

// Create: alloc and return pointer (point address)
Point *create_point(float x, float y); 

// Free: free point 
void free_point(Point *p); 

// Access: search point coordinates
int access_point(Point *p, float x, float y);

// Assign: assign point coordinates
int assign_point(Point *p, float x, float y);

// Distance: return the distance between two points
float point_distance(Point *p1, Point *p2);