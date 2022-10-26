import logging as log
import re

from tree_sitter import Node

from Patches.HelperMethods import get_text
from Patches.Patch import Patch


class Namespace(Patch):
    """
    Patch   namespace {CONTENT}
    to      CONTENT
    """

    def __init__(self, priority: int):
        super().__init__(priority)

    def get_search_pattern(self) -> str:
        return "(namespace_definition" "   (declaration_list) @decl_list" ") @namespace_def"

    def get_main_capture_name(self) -> str:
        return "namespace_def"

    def get_patch(self, captures: [(Node, str)], src: bytes, **kwargs) -> bytes:
        decl_list = captures[1][0]
        dl = get_text(src, decl_list.start_byte, decl_list.end_byte).strip(b"{}")
        return dl
