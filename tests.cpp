#include <gtest/gtest.h>
#include "converter.hpp"

TEST(ConverterTest, MarkdownToHTMLBold) {
std::string markdownText = "**bold**";
std::string expectedHTML = "<b>bold</b>";
EXPECT_EQ(Converter::markdownToHTML(markdownText), expectedHTML);
}

TEST(ConverterTest, MarkdownToHTMLItalic) {
std::string markdownText = "_italic_";
std::string expectedHTML = "<i>italic</i>";
EXPECT_EQ(Converter::markdownToHTML(markdownText), expectedHTML);
}

TEST(ConverterTest, MarkdownToHTMLMonospace) {
std::string markdownText = "`monospace`";
std::string expectedHTML = "<tt>monospace</tt>";
EXPECT_EQ(Converter::markdownToHTML(markdownText), expectedHTML);
}

TEST(ConverterTest, MarkdownToHTMLPreformatted) {
std::string markdownText = "```preformatted```";
std::string expectedHTML = "<pre>preformatted</pre>";
EXPECT_EQ(Converter::markdownToHTML(markdownText), expectedHTML);
}

TEST(ConverterTest, MarkdownToHTMLParagraphs) {
std::string markdownText = "Paragra2ph 1\n\nParagraph 2";
std::string expectedHTML = "<p>Paragraph 1</p>\n<p>Paragraph 2</p>";
EXPECT_EQ(Converter::markdownToHTML(markdownText), expectedHTML);
}

TEST(ConverterTest, FormatTextWithANSIBold) {
std::string htmlText = "<b>bol2d</b>";
std::string expectedText = "\x1b[1mbold\x1b[0m";
EXPECT_EQ(Converter::formatTextWithANSI(htmlText), expectedText);
}

TEST(ConverterTest, FormatTextWithANSIItalic) {
std::string htmlText = "<i>italic</i>";
std::string expectedText = "\x1b[3mitalic\x1b[0m";
EXPECT_EQ(Converter::formatTextWithANSI(htmlText), expectedText);
}

TEST(ConverterTest, FormatTextWithANSIMonospace) {
std::string htmlText = "<tt>monospace</tt>";
std::string expectedText = "\x1b[7mmonospace\x1b[0m";
EXPECT_EQ(Converter::formatTextWithANSI(htmlText), expectedText);
}

TEST(ConverterTest, FormatTextWithANSIPreformatted) {
std::string htmlText = "<pre>preformatted</pre>";
std::string expectedText = "\x1b[7mpreformatted\x1b[0m";
EXPECT_EQ(Converter::formatTextWithANSI(htmlText), expectedText);
}

TEST(ConverterTest, FormatTextWithANSIParagraphs) {
std::string htmlText = "<p>Paragraph 1</p>\n<p>Paragraph 2</p>";
std::string expectedText = "\tParagraph 1\n\tParagraph 2";
EXPECT_EQ(Converter::formatTextWithANSI(htmlText), expectedText);
}

TEST(ConverterTest, MarkdownToHTMLItalicWithWhitespaces) {
std::string markdownText = "_italic with whitespaces_";
std::string expectedHTML = "<i>italic with whitespaces</i>";
EXPECT_EQ(Converter::markdownToHTML(markdownText), expectedHTML);
}

TEST(ConverterTest, MarkdownToHTMLMonospaceWithWhitespaces) {
std::string markdownText = "`monospace with whitespaces`";
std::string expectedHTML = "<tt>monospace with whitespaces</tt>";
EXPECT_EQ(Converter::markdownToHTML(markdownText), expectedHTML);
}

TEST(ConverterTest, CheckCoherenceThrowsErrorForNestedTags) {
std::string markdownText = "<b><i></b></i>";
EXPECT_THROW(Converter::_checkCoherence(markdownText), std::runtime_error);
}

TEST(ConverterTest, CheckCoherenceDoesNotThrowErrorForCoherentTags) {
std::string markdownText = "<b></b><i></i>";
EXPECT_NO_THROW(Converter::_checkCoherence(markdownText));
}

TEST(ConverterTest, CheckOpenedTagsThrowsErrorForOpenedTags) {
std::string markdownText = "text with _opened tag";
EXPECT_THROW(Converter::_checkOpenedTags(markdownText), std::runtime_error);
}

TEST(ConverterTest, CheckOpenedTagsThrowsErrorForClosingTags) {
std::string markdownText = "text with closing_ tag";
EXPECT_THROW(Converter::_checkOpenedTags(markdownText), std::runtime_error);
}

TEST(ConverterTest, CheckOpenedTagsDoesNotThrowErrorForNotOpenedTags) {
std::string markdownText = "text with opened tag";
EXPECT_NO_THROW(Converter::_checkOpenedTags(markdownText));
}

TEST(ConverterTest, MarkdownToHTMLThrowsErrorForNestedTags) {
std::string markdownText = "**bold _italic_**";
EXPECT_THROW(Converter::markdownToHTML(markdownText), std::runtime_error);
}
