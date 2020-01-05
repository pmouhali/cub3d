#include <stdint.h>

typedef struct	s_color
{
		uint8_t	a;
		uint8_t	r;
		uint8_t	g;
		uint8_t	b;
}		t_color;

typedef union	u_color
{
	uint32_t	color;
	t_color		argb;
}		t_colors;

int main(void)
{
	t_colors u;

	u.color = 0xFF0000FF;

	printf("%d %d %d %d\n", u.argb.a, u.argb.r, u.argb.g, u.argb.b);

	return (0);
}
