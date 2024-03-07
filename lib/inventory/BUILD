load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "inventory",
    srcs = ["inventory.cpp"],
    hdrs = ["inventory.h"],
    visibility = ["//main:__subpackages__"],
    deps = ["//lib/computer_parts:computer_parts"],
)