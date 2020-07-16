#ifndef SHAPE_HPP
#define SHAPE_HPP
class Shape {
	public:
		virtual float area(void) const = 0 ;
		virtual float volume(void) const  = 0 ;
	private:
};
#endif
