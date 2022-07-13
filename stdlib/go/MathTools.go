import "math"

type dynamic = interface{}

func arcsine(dynamic x, dynamic y) {
	return math.asin(x, y);
}
	
func arccos(dynamic x, dynamic y) {
	return math.acos(x, y);
}
	
func cosine(dynamic x, dynamic y) {
	return math.cos(x, y);
}
	
func power(dynamic x, dynamic y) {
	return math.pow(x, y);
}
	
func sine(dynamic x, dynamic y) {
	return math.sin(x, y);
}
	
func floorValues(dynamic x, dynamic y) {
	return math.floor(x, y);
}
	