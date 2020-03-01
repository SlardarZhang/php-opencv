/*
 +----------------------------------------------------------------------+
 | PHP-OpenCV                                                           |
 +----------------------------------------------------------------------+
 | This source file is subject to version 2.0 of the Apache license,    |
 | that is bundled with this package in the file LICENSE, and is        |
 | available through the world-wide-web at the following url:           |
 | http://www.apache.org/licenses/LICENSE-2.0.html                      |
 | If you did not receive a copy of the Apache2.0 license and are unable|
 | to obtain it through the world-wide-web, please send a note to       |
 | hihozhou@gmail.com so we can mail you a copy immediately.            |
 +----------------------------------------------------------------------+
 | Author: HaiHao Zhou  <hihozhou@gmail.com>                            |
 +----------------------------------------------------------------------+
 */


#ifndef PHP_OPENCV_FACEREC_H
#define PHP_OPENCV_FACEREC_H
#ifdef HAVE_OPENCV_FACE
	#include <utility>
	typedef std::pair<int, double> FACE_PAIR;
	bool face_pair_cmp(const FACE_PAIR&, const FACE_PAIR&);

	/**
	 * Make Sure the float display in right way.
	 */
	static inline double float_to_double(float fp4, int decimals) {
		char* num_buf = new char[decimals+(static_cast<int>(fp4))];

		if (decimals < 0) {
			php_gcvt(fp4, FLT_DIG, '.', 'e', num_buf);
		} else {
			sprintf(num_buf, "%.*f", decimals, fp4);
		}
		delete num_buf;

		return zend_strtod(num_buf, NULL);
	}
#endif
#endif //PHP_OPENCV_FACEREC_H
extern void opencv_base_face_recognizer_init(int module_number);
