SET(${PY_NAME}_SOURCES
  ${PY_NAME}
  signal
  entity
  )

ADD_LIBRARY(${PY_NAME} SHARED ${${PY_NAME}_SOURCES})
PKG_CONFIG_USE_DEPENDENCY(${PY_NAME} "dynamic-graph")
TARGET_LINK_BOOST_PYTHON(${PY_NAME})

# This lib depends on python version, so we should not install it in the global prefix
INSTALL(TARGETS ${PY_NAME} DESTINATION ${${PY_NAME}_INSTALL_DIR})
# and we have to add this libdir to the .pc file
PKG_CONFIG_APPEND_LIBRARY_DIR("\\\${prefix}/${${PY_NAME}_INSTALL_DIR}")
