package cse405;

import com.google.appengine.api.datastore.DatastoreService;
import com.google.appengine.api.datastore.DatastoreServiceFactory;
import com.google.appengine.api.datastore.Entity;
import com.google.appengine.api.datastore.Query;
import com.google.appengine.api.datastore.Text;

// The application design is that authenticated users have zero or one messages.
//
// This class is not thread safe because it is possible to create 2 messages for
// a single user under the right conditions. Also, the static initialization
// code is not thread safe either. These problems can be solved using transactions.
//
// All application messages are placed under a single parent entity.
public class AdminMessage {

	private static final String entityKind = "AdminMessage";
	private static final String textPropertyName = "text";
	
	private Entity entity = null;

	private AdminMessage(Entity entity) {
		this.entity = entity;
	}

	public String getText() {
		return ((Text) entity.getProperty(textPropertyName)).getValue();
	}

	private void setText(String text) {
		entity.setProperty(textPropertyName, new Text(text));
	}

	private void save() {
		DatastoreService datastore = DatastoreServiceFactory.getDatastoreService();
		datastore.put(entity);	
	}

	public static AdminMessage createOrUpdate(String text) {
		AdminMessage message = getAdminMessage();
		if (message != null) {
				message.setText(text);
		} else {
				Entity entity = new Entity(entityKind);
				entity.setProperty(textPropertyName, new Text(text));
				message = new AdminMessage(entity);
		}
		message.save();
		return message;
	}

	public static AdminMessage getAdminMessage() {
		Query query = new Query(entityKind);
		DatastoreService datastore = DatastoreServiceFactory.getDatastoreService();
		Entity entity = datastore.prepare(query).asSingleEntity();
		if (entity == null) {
			entity = new Entity(entityKind);
			entity.setProperty(textPropertyName, new Text("Default Admin Message"));
			AdminMessage message = new AdminMessage(entity);
			message.save();
			return message;
		} else {
			return new AdminMessage(entity);
		}
	}
}