
#  This file is part of the DSP-Crowd project
#  https://www.dsp-crowd.com

#  Author(s):
#      - Johannes Natter, office@dsp-crowd.com

#  Copyright (C) 2017 Authors and www.dsp-crowd.com

#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.

#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#  GNU General Public License for more details.

#  You should have received a copy of the GNU General Public License
#  along with this program. If not, see <http://www.gnu.org/licenses/>.

#AC_CONFIG_AUX_DIR([.aux])

AC_INIT([DSP-Crowd irenc], [17.4-1], [office@dsp-crowd.com], [irenc], [www.dsp-crowd.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

AC_PROG_CC
AC_PROG_CXX
AM_PROG_AR

AM_SILENT_RULES([yes])
AC_CONFIG_HEADERS([config.h])

LT_INIT

AC_CANONICAL_HOST
case ${host} in
	*mingw*)
		HAL_TYPE='windows' ;;
	*linux*)
		HAL_TYPE='linux' ;;
	*)
		HAL_TYPE='generic' ;;
esac
AC_SUBST([HAL_TYPE])
case ${host} in
	*arm*)
		TARGET_PI=1 ;;
	*)
		TARGET_PI=0 ;;
esac
AC_SUBST([TARGET_PI])
AM_CONDITIONAL([BUILD_PIGPIO], [test x$TARGET_PI = x1])

AC_CONFIG_FILES([
	Makefile
	src/Makefile
	src/hal/Makefile
	src/hal/generic/Makefile
	src/hal/linux/Makefile
	src/hal/windows/Makefile
	src/irenc/Makefile
	src/irenc/include/Makefile
	src/irenc/include/pigpio/Makefile
])

AC_OUTPUT
