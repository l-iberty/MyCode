package coreservlets;


public class SearchUtilities {
    private static SearchSpec[] commonSpecs =
            {
                    new SearchSpec("Bing", "http://cn.bing.com/search?q="),
                    new SearchSpec("Wiki", "https://en.wikipedia.org/wiki/")
            };

    public static SearchSpec[] getCommonSpecs() {
        return commonSpecs;
    }

    public static String makeURL(String searchEngineName, String searchString) {
        SearchSpec[] searchSpecs = getCommonSpecs();
        String searchURL = null;
        for (SearchSpec spec : searchSpecs) {
            if (spec.getName().equalsIgnoreCase(searchEngineName)) {
                searchURL = spec.makeURL(searchString);
                break;
            }
        }

        return searchURL;
    }
}
