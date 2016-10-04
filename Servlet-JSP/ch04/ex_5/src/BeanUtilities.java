package coreservlets.beans;

import java.util.Map;
import javax.servlet.http.*;
import org.apache.commons.beanutils.BeanUtils;

public class BeanUtilities {
	public static void populateBean(Object formBean, HttpServletRequest request) {
		populateBean(formBean, request.getParameterMap());
	}

	public static void populateBean(Object bean, Map<String, ? extends Object> propertyMap) {
		try {
			BeanUtils.populate(bean, propertyMap);
		} catch (Exception e) {
			// do nothing
		}
	}
}