package cse405;

import java.util.Iterator;
import com.google.appengine.api.datastore.DatastoreService;
import com.google.appengine.api.datastore.DatastoreServiceFactory;
import com.google.appengine.api.datastore.Entity;

import com.google.appengine.api.datastore.Query;
import com.google.appengine.api.datastore.Query.Filter;
import com.google.appengine.api.datastore.Query.FilterOperator;
import com.google.appengine.api.datastore.Query.FilterPredicate;
import com.google.appengine.api.datastore.Query.SortDirection;

// The application design is that authenticated users have zero or one messages.
//
// This class is not thread safe because it is possible to create 2 messages for
// a single user under the right conditions. Also, the static initialization
// code is not thread safe either. These problems can be solved using transactions.
//
// All application messages are placed under a single parent entity.
public class UserNumber {

  private static final String entityKind = "UserNumber";
  private static final String numberPropertyName = "number";
  private static final String userIdPropertyName = "userId";
  private Entity entity = null;

  private UserNumber(Entity entity) {
    this.entity = entity;
  }

  public long getNumber() {
    return (Long) entity.getProperty(numberPropertyName);
  }

  private void setNumber(int number) {
    entity.setProperty(numberPropertyName, new Integer(number));
  }

  private void save() {
    DatastoreService datastore = DatastoreServiceFactory.getDatastoreService();
	datastore.put(entity);
  }

  public static UserNumber createOrUpdate(int number, String userId) {
	UserNumber userNumber = getUserNumber(userId);
	if (userNumber != null) {
	  userNumber.setNumber(number);
	} else {
	  Entity entity = new Entity(entityKind);
	  entity.setProperty(userIdPropertyName, userId);
	  entity.setProperty(numberPropertyName, new Integer(number));
	  userNumber = new UserNumber(entity);
	}
	userNumber.save();
	return userNumber;
  }

  public static UserNumber getUserNumber(String userId) {	 
    Filter filter = new FilterPredicate(userIdPropertyName,FilterOperator.EQUAL,userId);
		
    Query query = new Query(entityKind).setFilter(filter);
	
	DatastoreService datastore = DatastoreServiceFactory.getDatastoreService();
	Entity entity = datastore.prepare(query).asSingleEntity();
	if (entity == null) {
	  entity = new Entity(entityKind);
	  entity.setProperty(userIdPropertyName, userId);
	  entity.setProperty(numberPropertyName, new Integer(0));
	  UserNumber userNumber = new UserNumber(entity);
	  userNumber.save();
	  return userNumber;
	} else {
	  return new UserNumber(entity);
    }
  }
		
  public static long largestValue() {
    Query query = new Query(entityKind).addSort(numberPropertyName, SortDirection.DESCENDING);
	DatastoreService datastore = DatastoreServiceFactory.getDatastoreService();
	Iterator<Entity> entityIter = datastore.prepare(query).asIterator();
		
	if(entityIter != null) {
	  UserNumber highestNumber = new UserNumber(entityIter.next());
	  return highestNumber.getNumber();
	}
	else {
	  return 0;
	}
  }	
}



	
	