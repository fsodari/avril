"""
Check that the package was built correctly and the basic features work.
"""

import avril


def test_pkg_info():
    """"""
    assert avril.hello_from_bin() == "Hello, Avril!"
