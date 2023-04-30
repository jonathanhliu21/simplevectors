project = "simplevectors"
copyright = "2023, Jonathan Liu"
author = "Jonathan Liu"
release = "0.3.7"
extensions = ["breathe", "exhale"]
breathe_projects = {"simplevectors": "../_build/xml"}
breathe_default_project = "simplevectors"
exhale_args = {
    "containmentFolder": "./api",
    "rootFileName": "library_root.rst",
    "doxygenStripFromPath": "..",
    "rootFileTitle": "Library API",
    "createTreeView": True,
}
html_theme = "sphinx_rtd_theme"
